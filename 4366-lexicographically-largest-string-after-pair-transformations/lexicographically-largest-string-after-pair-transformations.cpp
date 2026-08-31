class Solution {
private:
    vector<string> hash = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "zz", "zzzz", "zzzzzzzz"};
    string f(int n){
        string res;
        for(int i=28; i>=0; i--){
            if(n&(1<<i)) res += hash[i];
        }
        return res;
    }
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;
        for(auto &n : nums) ans.push_back(f(n));
        return ans;
    }
};