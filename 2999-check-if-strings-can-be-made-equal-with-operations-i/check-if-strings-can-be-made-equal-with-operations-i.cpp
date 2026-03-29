class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        bool op1 = (s1 == s2);
        bool op2 = (s1[0] == s2[2] && s1[2] == s2[0] && s1[1] == s2[1] && s1[3] == s2[3]);
        bool op3 = (s1[0] == s2[2] && s1[2] == s2[0] && s1[1] == s2[3] && s1[3] == s2[1]);
        bool op4 = (s1[0] == s2[0] && s1[2] == s2[2] && s1[1] == s2[3] && s1[3] == s2[1]);
        if(op1 || op2 || op3 || op4) return  true;
        return false;
    }
};