class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int m = buildings.size();
        unordered_map<int, int> xlmpp, xhmpp, ylmpp, yhmpp;
        for(int i=0; i<m; i++){
            int x = buildings[i][0], y = buildings[i][1];
            xlmpp[x] = (xlmpp[x] == 0? y : min(xlmpp[x], y));
            xhmpp[x] = max(xhmpp[x], y);
            ylmpp[y] = (ylmpp[y] == 0? x : min(ylmpp[y], x));
            yhmpp[y] = max(yhmpp[y], x);
        }
        int cnt = 0;
        for(int i=0; i<m; i++){
            int x = buildings[i][0], y = buildings[i][1];
            if(y == xlmpp[x] || y == xhmpp[x] || x == ylmpp[y] || x == yhmpp[y]) continue;
            else cnt++;
        }
        return cnt;  
    }
};