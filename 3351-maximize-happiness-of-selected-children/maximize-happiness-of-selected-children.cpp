class Solution {
public:
    long long maximumHappinessSum(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.rbegin(), arr.rend());
        long long sum = 0, dec = 0;
        for(int i=0; i<n && k; i++){
            if(arr[i] - dec > 0){
                sum += (arr[i] - dec);
                dec++;
                k--;
            }
            else break;
        }
        return sum;
    }
};