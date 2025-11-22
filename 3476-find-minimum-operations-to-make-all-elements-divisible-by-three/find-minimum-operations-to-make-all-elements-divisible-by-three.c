int minimumOperations(int* nums, int n) {
    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(nums[i] % 3 != 0) cnt++;
    }
    return cnt;
}