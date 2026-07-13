class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int l = low, h = high, lw = 0, rw = 0;
        while(l){
            lw++;
            l /= 10;
        }
        while(h){
            rw++;
            h /= 10;
        }
        vector<int> ans;
        int num = 123456789, leftr = 9-lw, tens = 1, mods = 1;
        for(int i=1; i<=leftr; i++) tens *= 10;
        for(int i=1; i<=lw; i++) mods *= 10;
        for(int w=lw; w<=rw; w++){
            int temp = tens;
            while(temp){
                int val = (num/temp)%mods;
                if(val>=low && val<=high) ans.push_back(val);
                temp /= 10;
            }
            tens /= 10;
            if(mods < 1000000000) mods *= 10;
        }
        return ans;
    }
};