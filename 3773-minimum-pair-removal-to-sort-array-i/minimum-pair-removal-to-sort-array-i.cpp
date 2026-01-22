class Solution {
private:
    int f(vector<int>& nums){
        int idx = -1, mini = INT_MAX;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]+nums[i+1] < mini){
                idx = i;
                mini = nums[i]+nums[i+1];
            }
        }
        return idx;
    }
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        int op=0;
        while(!is_sorted(begin(nums),end(nums))){
            int idx = f(nums);
            nums[idx] = nums[idx]+nums[idx+1];
            nums.erase(nums.begin()+idx+1);
            cout<<nums[idx]<<' ';
            op++;
        }
        return op;
    }
};