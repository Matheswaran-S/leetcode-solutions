class Solution {
public:
    bool check(int mid, vector<int> &piles, int h){
        for(int i=0; i<piles.size(); i++){
            if(h >= (piles[i]+mid-1)/mid) h -= (piles[i]+mid-1)/mid;
            else return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = 1e9;
        while(lo <= hi){
            int mid = lo+(hi-lo)/2;
            if(check(mid, piles, h)) hi = mid-1;
            else lo = mid+1;
        }
        return lo;
    }
};