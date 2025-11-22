class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> st;
        int n = fruits.size();
        int cnt = 0, l=0, r=0;
        while(r < n){
            st[fruits[r]]++;
            if(st.size() > 2){
                st[fruits[l]]--;
                if(st[fruits[l]] == 0) st.erase(fruits[l]);
                l++;
            }
            cnt = max(cnt, r-l+1);
            r++;
        }
        return cnt;
    }
};