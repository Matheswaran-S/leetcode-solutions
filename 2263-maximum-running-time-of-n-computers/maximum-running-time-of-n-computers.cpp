class Solution {
public:
    bool check(long long mid, int n, vector<int> &batteries){
        long long target = mid*n;
        for(auto i : batteries){
            target = i < mid ? target - i : target - mid; // target -= min(i,mid)
            if(target <= 0) return true;
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long mini = LLONG_MAX;
        long long sum = 0;
        for(auto i : batteries){
            mini = i < mini ? i : mini; //min(i, mini);
            sum += i;
        }
        long long low=mini, high=sum/n;

        while(low <= high){
            long long mid = low+(high-low)/2;
            if(check(mid, n, batteries)){
                low = mid+1;
            }
            else high = mid-1;
        }

        return high;//BS on Answers low will cross high (opposite polarity)
    }
};