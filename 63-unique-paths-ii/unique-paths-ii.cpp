class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][obstacleGrid[0].size()-1] == 1) return 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<obstacleGrid[i].size(); j++){
                if(obstacleGrid[i][j] == 1) obstacleGrid[i][j] = -1;
            }
        }
        for(int i=0; i<n; i++){
            if(obstacleGrid[i][0] == -1) break;
            obstacleGrid[i][0] = 1;
        }
        for(int j=0; j<obstacleGrid[0].size(); j++){
            if(obstacleGrid[0][j] == -1) break;
            obstacleGrid[0][j] = 1;
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<obstacleGrid[i].size(); j++){
                if(obstacleGrid[i][j] == -1) continue;
                if(obstacleGrid[i-1][j] == -1 || obstacleGrid[i][j-1] == -1){
                    obstacleGrid[i][j] = max(obstacleGrid[i-1][j], obstacleGrid[i][j-1]);
                }
                else{
                    obstacleGrid[i][j] = obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
                }
            }
        }
        return obstacleGrid[n-1][obstacleGrid[0].size()-1] < 0 ? 0 : obstacleGrid[n-1][obstacleGrid[0].size()-1];
    }
};