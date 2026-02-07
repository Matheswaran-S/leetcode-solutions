class Solution {
private:
    bool rec(int mid, vector<int> &jobs, vector<int> &w, int k, int n, int idx){
        if(idx == n) return true;
        for(int i=0; i<k; i++){
            if(w[i]+jobs[idx] <= mid){
                w[i] += jobs[idx];
                if(rec(mid, jobs, w, k, n, idx+1)) return true;
                w[i] -= jobs[idx];
            }
            if(w[i] == 0) break;
        }
        return false;
    }
    bool check(int mid, vector<int> &jobs, int k, int n){
        vector<int> w(k, 0);
        return rec(mid,jobs,w,k,n,0);
    }
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.rbegin(), jobs.rend());
        int lo = jobs[0];
        int hi = accumulate(jobs.begin(), jobs.end(), 0);
        while (lo <= hi) {
            int mid = lo+(hi-lo)/2;
            if (check(mid, jobs, k, jobs.size())) hi = mid-1;
            else lo = mid+1;
        }
        return lo;
    }
};
