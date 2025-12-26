class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size(), ans = 0;
        int penalty = n, prev = n; 
        for(int i=0; i<n; i++){
            if(customers[i] == 'Y') penalty--;
            else penalty++;
            if(penalty < prev){
                prev = penalty;
                ans = i+1;
            }
        }
        return ans;
    }
};