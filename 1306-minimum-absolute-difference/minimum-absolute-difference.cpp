class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> v;
        sort(arr.begin(), arr.end());
        int diff = INT_MAX;
        for(int i=0; i<arr.size()-1; i++){
            if(diff >= arr[i+1] - arr[i]){
                if(diff == arr[i+1] - arr[i]) v.push_back({arr[i],arr[i+1]});
                else{
                    diff = arr[i+1] - arr[i];
                    v.clear();
                    v.push_back({arr[i], arr[i+1]});
                }
            }
        }
        return v;
    }
};