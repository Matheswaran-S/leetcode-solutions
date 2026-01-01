class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), idx = -1;
        for(int i=n-1; i>=0; i--){
            if(digits[i] == 9) idx = i;
            else break;
        }
        if(idx == -1){
            digits[n-1] += 1;
            return digits;
        }     
        else if(idx > 0){
            digits[idx - 1] += 1;
            for(int i=idx; i<n; i++) digits[i] = 0;
            return digits;
        }
        else{
            vector<int> v(n+1,0);
            v[0] = 1;
            return v;
        }
    }
};