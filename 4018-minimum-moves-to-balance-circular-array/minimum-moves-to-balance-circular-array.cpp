class Solution {
public:
    long long minMoves(vector<int>& arr) {
        int n = arr.size(), id = -1;
        long long sum = 0, moves = 0;
        for(int i=0; i<n; i++){
            if(arr[i] < 0){
                id = i;
            }
            sum += arr[i];
        }
        if(id == -1) return 0;
        if(sum < 0) return -1;
        int l = (id-1+n)%n, r = (id+1)%n, len = 1;
        while(l >= 0 && r < n){
            long long  lft = min(abs(arr[id]), arr[l]);
            arr[id] += lft;
            long long rgt = min(abs(arr[id]), arr[r]);
            arr[id] += rgt;
            moves += abs(len*rgt) + abs(len*lft);
            
            if(arr[id] == 0) return moves;
            l = (l-1+n)%n, r = (r+1)%n;
            len++;
        }
        return moves;
    }
};