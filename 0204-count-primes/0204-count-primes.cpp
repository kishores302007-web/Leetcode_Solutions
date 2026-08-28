class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        bool dp[n];
        for (int j = 0; j < n; j++) {
            dp[j] = true;
        }
        dp[0] = false;
        dp[1] = false;
        for (int i = 2; i * i < n; i++) {
            if (dp[i]) {
                for (int j = i * i; j < n; j += i) {
                    dp[j] = false;
                }
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (dp[i]) {
                count++;
            }
        }
        return count;
    }
};