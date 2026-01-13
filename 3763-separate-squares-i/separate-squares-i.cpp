#define ll long long
class Solution {
private:
    double cont(double r, vector<vector<int>>& squares){
        double area = 0;
        for(auto &i : squares){
            if(i[1] < r){
                area += min(1.0*i[2]*i[2], i[2]*(r-i[1]));
            }
        }
        return area;
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        double total = 0;
        for(auto &i : squares){
            total += ((ll)i[2]*(ll)i[2]);
        }
        double lo = 0, hi = 1e9, half = total/2;
        while(hi - lo > 1e-6){
            double mid = lo+(hi-lo)/2;
            double area = cont(mid, squares);
            if(area < half) lo = mid;
            else hi = mid;
        }
        return hi;
    }
};