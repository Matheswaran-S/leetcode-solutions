class Solution {
private:
    int reverse(int x){
        int n = 0;
        while(x > 0){
            n *= 10;
            n += (x%10);
            x /= 10;
        }
        return n;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size(), mindst = INT_MAX;
        unordered_map<int, int> mpp;
        for(int i=n-1; i>=0; i--){
            int rev = mpp[reverse(nums[i])];
            if(rev){
                mindst = min(mindst, rev - i);
            }
            mpp[nums[i]] = i;
        }
        return mindst == INT_MAX ? -1 : mindst;
    }
};