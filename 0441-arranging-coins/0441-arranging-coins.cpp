class Solution {
public:
    int arrangeCoins(int n) {
        long long left = 1;
        long long right = n;
        while (right >= left) {
            long long mid = left + (right - left) / 2;
            long long coin = mid * (mid + 1) / 2;
            if (coin <= n) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};