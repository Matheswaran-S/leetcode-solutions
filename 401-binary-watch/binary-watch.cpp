class Solution {
private:
    void rec(vector<string> &ans, vector<int> &arr, int cnt, int ind, int hr, int min, int t){
        if(cnt > t) return;
        if(hr > 11 || min > 59) return;
        if(ind == 10){
            if(cnt == t){
            string m = "";
            if(min < 10) m += '0';
            ans.push_back(to_string(hr)+':'+m+to_string(min));
            cout<<to_string(hr)+':'+m+to_string(min)<<'\n';
            return;
        }
        }
        if(ind < 4) hr += arr[ind];
        else if(ind<10) min += arr[ind];
        rec(ans, arr, cnt+1, ind+1, hr, min, t);
        if(ind < 4) hr -= arr[ind];
        else if(ind < 10) min -= arr[ind];
        if(ind < 10)rec(ans, arr, cnt, ind+1, hr, min, t);
    }
public:
    vector<string> readBinaryWatch(int t) {
        vector<int> arr = {1,2,4,8,1,2,4,8,16,32};
        vector<string> ans;
        rec(ans, arr, 0, 0, 0, 0, t);
        return ans;
    }
};