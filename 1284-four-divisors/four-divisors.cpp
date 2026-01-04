class Solution {
private:
    int div(int n){
        int sum = 0, cnt = 0;
        for(int i=1; i*i<=n; i++){
            if(n%i == 0){
                sum += i;
                sum += n/i;
                cnt += 2;
                if(n/i == i){
                    sum -= i;
                    cnt--;
                }
            }
            if(cnt > 4) break;
        }
        if(cnt == 4) return sum;
        return 0;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int i=0; i<n; i++){
            sum += div(nums[i]);
        }
        return sum;
    }
};