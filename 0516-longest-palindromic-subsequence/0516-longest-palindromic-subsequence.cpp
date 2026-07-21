class Solution {
public:
    int longestPalindromeSubseq(string t1) {
        string t2 = t1;
        reverse(t2.begin(), t2.end());
        int n = t1.size();
        int arr[n+1][n+1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    arr[i][j] = 0;
                } else if (t1[i - 1] == t2[j - 1]) {
                    arr[i][j] = arr[i - 1][j - 1] + 1;
                } else {
                    arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
                }
            }
        }
        return arr[n][n];
    }
};