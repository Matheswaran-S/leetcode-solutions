#define ll long long
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        ll k = k1+k2;
        vector<int> diff;
        for(int i=0; i<n; i++){
            diff.push_back(abs(nums1[i]-nums2[i]));
        }
        sort(diff.rbegin(), diff.rend());
        map<int,int> mpp, next;
        for(int i=0; i<n; i++){
            mpp[diff[i]]++;
            next[diff[i]] = (i+1 < n)? diff[i+1] : -1;
        }
        int cur = diff[0];
        while(k > 0){
            int nxt = next[cur];
            int frq = mpp[cur];
            if(nxt == -1){
                mpp[cur] = 0;
                int div = k/frq, rem = k%frq;
                mpp[max(0,cur-div)] += (frq-rem);
                mpp[max(0, cur-div-1)] += rem;
                k = 0;
                break;
            }
            if(k >= 1LL*(cur-nxt)*frq){
                mpp[cur] = 0;
                mpp[nxt] += frq;
                k -= 1LL*(cur-nxt)*frq;
                cur = nxt;
                continue;
            }
            else{
                mpp[cur] = 0;
                int div = k/frq, rem = k%frq;
                mpp[max(0,cur-div)] += (frq-rem);
                mpp[max(0, cur-div-1)] += rem;
                k = 0;
                break;
            }
        }
        ll ans = 0;
        for(auto &[x,y] : mpp){
            ans += (1LL*x*x*y);
        }
        return ans;
        /*12 10  9 9 9 7 2     k = 5
        10 10  9 9 9 7 2     k = 3
        9  9   9 9 9 7 2     k = 1
        9  9   9 9 8 7 2     k = 0*/
    }
};