class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = min(n,8);
        n = n - 8;
        if(n <= 0) return ans;
        ans += min(8*2, n*2);
        n = n-8;
        if(n <= 0) return ans;
        ans += min(8*3, n*3);
        n -= 8;
        if(n <= 0) return ans;
        return ans+n*4;
    }
};