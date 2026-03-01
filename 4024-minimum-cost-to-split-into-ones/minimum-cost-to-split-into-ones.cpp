class Solution {
public:
    int minCost(int n) {
        if(n==1) return 0;
        queue<int> q;
        q.push(n);
        int ans  = 0;
        //vector<int> dp(n+1, -1);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            int a = x/2;
            int b = x/2;
            if(x&1) b = b+1;
            
            ans += (a*b);
            if(a != 1) q.push(a);
            if(b != 1) q.push(b);
        }
        return ans;
    }
};