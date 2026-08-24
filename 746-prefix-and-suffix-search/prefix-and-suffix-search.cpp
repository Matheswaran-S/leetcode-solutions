class WordFilter {
private:
    map<pair<string,string>,int> mpp;
public:
    WordFilter(vector<string>& words) {
        int i=0;
        for(auto &s : words){
            vector<string> pre, suf;
            string pr,sf;
            for(int i=0; i<s.size(); i++){
                pr += s[i];
                sf = s[s.size()-i-1]+sf;
                pre.push_back(pr);
                suf.push_back(sf);
            }
            for(auto &s1 : pre){
                for(auto &s2 : suf){
                    mpp[{s1,s2}] = max(mpp[{s1,s2}], i+1);
                }
            }
            i++;
        }
    }
    
    int f(string pref, string suff) {
        if(!mpp[{pref,suff}]) return -1;
        return mpp[{pref,suff}]-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */