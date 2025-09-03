class Solution {
public:
    int minBitFlips(int start, int goal) {
        //3 - 011 4 - 100 : x = 111 - 7  , 10 - 1010 7 - 0111 x= 1101 - 13
        int x = start^goal, cnt = 0;
        for(int i=0; i<=30; i++){
            if(x&(1<<i)) cnt++;

        }
        return cnt;
    }
};