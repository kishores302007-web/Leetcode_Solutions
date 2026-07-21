class Solution {
public:
    int minDistance(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        int arr[n + 1][m + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) {
                    arr[i][j] = 0;
                } else if (text1[i - 1] == text2[j - 1]) {
                    arr[i][j] = arr[i - 1][j - 1] + 1;
                } else {
                    arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
                }
            }
        }
        return m+n-2*arr[n][m];
    }
};