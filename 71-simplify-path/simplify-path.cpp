class Solution {
public:
    string reverse(string ans){
        int l=0,r=ans.size()-1;
        while(l<r){
            swap(ans[l],ans[r]);
            l++;
            r--;
        }
        return ans;
    }
    string simplifyPath(string path) {
        string ans = "";
        stack<char> st;
        int n = path.size();
        for(int i=0; i<n; i++){
            if(st.empty() && path[i] == '/') st.push(path[i]);
            else if(path[i] == '/' && !st.empty()){
                while(!st.empty() && st.top() == '/') st.pop();
                st.push('/');
            }
            else if(path[i] == '.'){
                int cnt = 1,ind = i;
                while(i+1 < n){
                    i++;
                    if(path[i] == '.'){
                        cnt++;
                        if(cnt >= 3 && !st.empty()) st.push('.');
                    }
                    else{
                        i--;
                        break;
                    }
                }
                if(cnt >= 3 && !st.empty()){
                    st.push('.');
                    st.push('.');
                }
                else if(st.empty()) continue;
                else{
                    if(i+1 < n && path[i+1] != '/' || ind > 0 && path[ind-1] != '/'){
                        while(cnt--){
                            st.push('.');
                        }
                    }
                    while(!st.empty() && cnt>0){
                        cout<<cnt;
                        if(st.top() == '/') {
                            cnt--;
                        }
                        if(cnt && !st.empty()) st.pop();
                    }
                    if(st.empty()) st.push('/');
                }
            }
            else{
                if(!st.empty()) st.push(path[i]);
            }
        }
        if(n>1 && st.size()>1 && st.top() == '/') st.pop();
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return reverse(ans);
    }
};