class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = speed.size(), pre = speed[0];
        vector<int> velo;
        for(int i=1; i<n; i++){
            if(position[i] - position[i-1] <= distance){
                pre = speed[i];
                continue;
            }
            velo.push_back(pre);
            pre = speed[i];
        }
        velo.push_back(pre);
        int m = velo.size();
        stack<int> st;
        st.push(velo[0]);
        for(int i=1; i<m; i++){
            int val = velo[i];
            while(!st.empty() && st.top() > val) st.pop();
            st.push(val);
        }
        return st.size();
    }
};