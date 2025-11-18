class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;
        int l = 0, r = 0, maxlen = 0, n = s.size();
        while(l <= r && r < n){
            if(mpp.find(s[r]) != mpp.end() && mpp[s[r]] >= l){
                l = mpp[s[r]]+1;
            }
            maxlen = max(maxlen, r-l+1);
            mpp[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};