class Solution {
public:
    string intToRoman(int num) {
        map<int,char> mpp;
        mpp[1] = 'I';
        mpp[5] = 'V';
        mpp[10] = 'X';
        mpp[50] = 'L';
        mpp[100] = 'C';
        mpp[500] = 'D';
        mpp[1000] = 'M';
        int dec = 1000;
        string s;
        while(num > 0){
            if(num/dec == 4){
                s.push_back(mpp[dec]);
                s.push_back(mpp[dec*5]);
                num %= dec;
            }
            else if(num/dec == 9){
                s.push_back(mpp[dec]);
                s.push_back(mpp[dec*10]);
                num %= dec;
            }
            else{
                int c = num/dec;
                if(c/5){
                    s.push_back(mpp[dec*5]);
                    num -= (dec*5);
                }
                c = num/dec;
                while(c--){
                    s.push_back(mpp[dec]);
                }
                num %= dec;
            }
            dec /= 10;
        }
        return s;
    }
};