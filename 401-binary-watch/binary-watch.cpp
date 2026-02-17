class Solution {
public:
    vector<string> readBinaryWatch(int t) {
        vector<string> ans;
        for(int i=0; i<12; i++){
            for(int j=0; j<60; j++){
                if(__builtin_popcount(i)+__builtin_popcount(j) == t){
                    string m =  "";
                    if(j < 10) m += '0';
                    ans.push_back(to_string(i)+':'+m+to_string(j));
                }
            }
        }
        return ans;
    }
};