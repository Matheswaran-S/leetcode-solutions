class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = healths.size();
        vector<vector<int>> robo(n, vector<int>(2));
        for(int i=0; i<n; i++){
            robo[i][0] = positions[i];
            if(directions[i] == 'R') robo[i][1] = healths[i];
            else robo[i][1] = -healths[i];
        }
        sort(robo.begin(), robo.end());
        stack<pair<int,int>> st;
        unordered_map<int,int> mpp;
        for(int i=0; i<n; i++){
            int curh = robo[i][1], curp = robo[i][0];
            while(!st.empty() && st.top().first>0 && curh < 0){
                int prh = st.top().first;
                int prp = st.top().second;
                if(st.top().first == abs(curh)){
                    st.pop();
                    mpp[prp] = 0;
                    curh = 0;
                }
                else if(st.top().first > abs(curh)){
                    st.pop();
                    prh--;
                    if(prh){
                        st.push({prh, prp});
                        mpp[prp] = prh;
                    }
                    curh = 0;
                }
                else{
                    st.pop();
                    mpp[prp] = 0;
                    curh++;
                }
            }
            if(curh){
                st.push({curh,curp});
                mpp[curp] = abs(curh);
            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(mpp[positions[i]]) ans.push_back(mpp[positions[i]]);
        }
        return ans;
    }
};