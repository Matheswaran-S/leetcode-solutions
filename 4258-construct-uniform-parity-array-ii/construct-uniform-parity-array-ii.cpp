class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        if(n == 1) return true;
        int mini = INT_MAX;        
        int odd = 0;
        for(int i=0; i<n; i++){
            if(nums1[i]&1) odd++;
            mini = min(mini, nums1[i]);
        }
        int feve = (mini%2 == 0);
        if(feve && odd) return false;
        return true;
    }
};