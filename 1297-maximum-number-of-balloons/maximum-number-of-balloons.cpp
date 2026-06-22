class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b = 0, a=0,  l=0, o=0, n=0, mini = 0;
        for(char &c : text){
            if(c == 'b') b++;
            else if(c == 'a') a++;
            else if(c == 'l') l++;
            else if(c == 'o') o++;
            else if(c == 'n') n++;
        }
        mini = min(b, a);
        mini = min(mini, l/2);
        mini = min(mini, o/2);
        mini = min(mini, n);
        return mini;
    }
};