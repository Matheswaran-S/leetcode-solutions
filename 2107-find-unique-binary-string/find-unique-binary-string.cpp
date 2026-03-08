class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_map<string,bool> mpp;
        for(auto &s : nums) mpp[s] = true;
        string temp(n,'0');
        if(!mpp[temp]) return temp;
        for(int i=0; i<n; i++){
            temp[i] = '1';
            if(!mpp[temp]) return temp;
            temp[i] = '0';
        }
        return temp;
    }
};