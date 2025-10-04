class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v(n);
        int fact = 1, j = n;k--;
        for(int i=0; i<n; i++){
            v[i] = i+1;
            fact *= (i+1);
        }
        string s;
        for(int i = 0 ; i < j-1; i++){
            fact = fact/n;
            s += (v[k/fact] + '0');
            v.erase(v.begin() + k/fact);
            k = k%fact;
            n--;
        }
        s += (v[0] + '0');
        return s;
    }
};