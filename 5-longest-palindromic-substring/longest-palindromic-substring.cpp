class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int l = i,r = j;
                bool f = true;
                while(l <= r && f){
                    if(s[l] != s[r]) f = false;
                    l++;r--;
                }
                if(f){
                    if(ans.size() < (j-i+1)){
                        //cout<<j-i+1;
                        ans = "";
                        for(int k=i; k<=j; k++){
                            //cout<<'\n'<<k<<endl;
                            ans.push_back((char)s[k]);
                        }
                    }
                }
            }
        }
        return ans;
    }
};