#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<int, null_type, std::less_equal<int>, rb_tree_tag, 
             tree_order_statistics_node_update> indexed_multiset;

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        indexed_multiset ms;
        ms.insert(nums1[0] - nums2[0]);
        long long n = nums1.size(), ans = 0;
        for(int i=1; i<n; i++){
            long long cnt = ms.order_of_key(nums1[i] - nums2[i]+diff+1);
            ans += cnt;
            ms.insert(nums1[i] - nums2[i]);
        }
        return ans;
    }
};