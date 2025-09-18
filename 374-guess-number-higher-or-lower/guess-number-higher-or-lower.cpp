/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        int mid = low + (high - low)/2;
        while(guess(mid)){
            if(guess(mid) == 0) return mid;
            else if(guess(mid) == -1){
                high = mid-1;
                mid = low + (high - low)/2;
            }
            else if(guess(mid) == 1){
                low = mid+1;
                mid = low + (high - low)/2;
            } 
        }
        return mid;
    }
};