class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        int i = 0, num = 0;
        while(i < n){
            while(num > 0 && num <= n){
                if(i < n)ans[i] = num;
                else break;
                i++;
                num *= 10;
            }
            num = num/10;
            while(num%10 == 9) num = num/10;
            num++;
        }
        return ans;
    }
};