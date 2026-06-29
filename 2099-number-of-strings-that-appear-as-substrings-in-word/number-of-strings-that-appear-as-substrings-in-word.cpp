class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for(auto &s : patterns){
            if(s.size() > word.size()) continue;
            else{
                int l=0, r = s.size()-1;
                while(r < word.size()){
                    if(s == word.substr(l, r-l+1)){
                        cnt++;
                        break;
                    }
                    l++; r++;
                }
            }
        }
        return cnt;
    }
};