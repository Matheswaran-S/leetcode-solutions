class Solution {
public:
    bool valid(int n){
        while(n > 0){
            if(n%10 == 0) return false;
            n = n/10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1; i<=n/2; i++){
            if(valid(i) && valid(n-i)) return{i, n-i};
        }
        return {1,n-1};
    }
};