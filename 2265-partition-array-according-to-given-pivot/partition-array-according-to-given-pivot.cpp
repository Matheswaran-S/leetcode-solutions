class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);
        int mi = 0, ze = 0, on = 0;
        for(auto &el : nums){
            if(el < pivot) mi++;
            else if(el == pivot) ze++;
        }
        on = ze + mi;
        ze = mi;
        mi = 0;
        for(auto &el : nums){
            if(el < pivot){
                ans[mi] = el;
                mi++;
            }
            else if(el == pivot){
                ans[ze] = el;
                ze++;
            }
            else{
                ans[on] = el;
                on++;
            }
        }
        return ans;
    }
};