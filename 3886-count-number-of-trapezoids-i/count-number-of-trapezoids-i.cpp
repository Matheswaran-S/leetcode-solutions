#define ll long long
#define mod 1000000007
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        ll res = 0;
        unordered_map<int,int> mpp;
        for(auto &i : points){
            
            mpp[i[1]]++;
        }
        ll prev = 0, cnt = 0;
        for(auto &i : mpp){
            cnt = i.second;
            cnt = (cnt)*(cnt-1)/2;
            res += prev*cnt;
            prev += cnt;
        }
        return res%mod;
    }
};