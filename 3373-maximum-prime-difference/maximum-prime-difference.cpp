class Solution {
public:
    void sieve(vector<bool> &sp){
        sp[1] = 0;
        for(int i=2; i*i<=100; i++){
            if(sp[i]){
                for(int j=i*i; j<=100; j+=i)
                {
                    sp[j] = 0;
                }
            }
        }
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int n = nums.size();
        vector<bool> sp(101,1);
        sieve(sp);
        int mn = INT_MAX, mx = INT_MIN;
        for(int i=0; i<n; i++){
            if(sp[nums[i]]){
                mn = min(mn, i);
                mx = max(mx, i);
            }
        }
        return mx-mn;
    }
};