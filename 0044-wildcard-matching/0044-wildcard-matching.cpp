class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> ans(n + 1, vector<bool>(m + 1, 0));

        ans[0][0] = 1;
        for (int i = 1; i <= m; i++) {
            if (p[i-1] == '*') {
                ans[0][i] = ans[0][i-1];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    ans[i][j] = ans[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    ans[i][j] = ans[i][j - 1] || ans[i - 1][j];
                }
            }
        }
        return ans[n][m];
    }
};