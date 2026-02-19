class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), p2=0, p1=0, cur=0;
        for(int i=0; i<n; i++){
            if(i==0) cur = nums[i];
            else{
                int t = nums[i];
                if(i > 1) t += p2;
                int nt = p1;
                cur = max(t,nt);
            }
            p2 = p1;
            p1 = cur;
        }
        return p1;
    }
};