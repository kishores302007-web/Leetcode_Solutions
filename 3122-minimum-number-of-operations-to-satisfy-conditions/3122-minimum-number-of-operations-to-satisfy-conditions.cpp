class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(10, 0);

        for (int j = 0; j < n; j++) {

            vector<int> count(10, 0);

            for (int i = 0; i < m; i++) {
                count[grid[i][j]]++;
            }

            vector<int> newDp(10, INT_MAX);

            for (int d = 0; d < 10; d++) {

                int cost = m - count[d];

                for (int prev = 0; prev < 10; prev++) {

                    if (prev == d)
                        continue;

                    newDp[d] = min(
                        newDp[d],
                        dp[prev] + cost
                    );
                }
            }

            dp = newDp;
        }

        return *min_element(dp.begin(), dp.end());
    }
};