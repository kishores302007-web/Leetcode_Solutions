class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int hr) {
        int l = 1;
        int h = *max_element(piles.begin(), piles.end());
        int result = 1;
        while (l <= h) {
            long long ans = 0, total = 0;
            int mid = l + (h - l) / 2;
            for (int i : piles) {
                if (i % mid == 0) {
                    ans = i / mid;
                } else {
                    ans = (i / mid) + 1;
                }
                total += ans;
            }
            if (total <= hr) {
                result = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }
};