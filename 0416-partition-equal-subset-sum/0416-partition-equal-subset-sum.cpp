class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        int n = nums.size(), target = sum / 2;
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(target + 1, 0));
        if (sum % 2 != 0) {
            return 0;
        } else {
            for (int i = 0; i < n; i++) {
                dp[i][0] = 1;
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j <= target; j++) {
                    if (nums[i - 1] <= j) {
                        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                    } else {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
        }
        return dp[n][target]  ? true : false;
    }
};