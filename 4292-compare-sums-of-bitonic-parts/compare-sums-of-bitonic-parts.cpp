class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long n = nums.size(), asc = nums[0], des = 0;
        bool desc = false;
        for(int i=1; i<n; i++){
            if(nums[i-1] < nums[i]) asc += nums[i];
            else{
                if(!desc){
                    desc = true;
                    des = nums[i-1];
                }
                des += nums[i];
            }
        }
        if(asc > des) return 0;
        else if(asc < des) return 1;
        return -1;
    }
};