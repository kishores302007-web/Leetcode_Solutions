class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        vector<int> ans(n);
        ans[0] = nums[0];
        ans[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++){
            ans[i] = max(ans[i-1], (ans[i-2] + nums[i]));
        }
        vector<int> ans2(n);
        ans2[0] = 0;
        ans2[1] = nums[1];
        for(int i = 2; i < n; i++){
            ans2[i] = max(ans2[i-1], (ans2[i-2] + nums[i]));
        }
       if(ans[n - 2] > ans2[n - 1]) return ans[n - 2];
       return ans2[n -1];
        
    }
};