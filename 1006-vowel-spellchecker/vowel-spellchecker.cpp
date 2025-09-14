class Solution {
public:
    string stolower(string &str){
        string result = "";
        for(auto s : str){
            result += tolower(s);
        }
        return result;
    }

    string tovowel(string &str){
        string result = "";
        for(auto s : str){
            if(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') result += '*';
            else result += s;
        }
        return result;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string,int> same;
        unordered_map<string,string> caps;
        unordered_map<string,string> vow;
        for(auto word : wordlist){
            same[word] = 1;
            string lower = stolower(word);
            if(caps.find(lower) == caps.end()) {
                caps[lower] = word;
            }
            string vowel = tovowel(lower);
            if(vow.find(vowel) == vow.end()){
                vow[vowel] = word;
            }
        }
        vector<string> ans;
        for(auto q : queries){
            string lower = stolower(q);
            string vowel = tovowel(lower);
            if(same[q] == 1) ans.push_back(q);
            else if(caps.find(lower) != caps.end()){
                ans.push_back(caps[lower]);
            }
            else if(vow.find(vowel) != vow.end()){
                ans.push_back(vow[vowel]);
            }
            else ans.push_back("");
        }
        return ans;
    }
};