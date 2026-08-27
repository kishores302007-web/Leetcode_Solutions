class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 0, r = *max_element(piles.begin(), piles.end());
        int result = 1;
        while (r >= l) {
            int mid = l + (r - l) / 2;
            int temp = 0, total = 0;
            for (int i : piles) {
                if (i % mid == 0) {
                    temp = i / mid;
                } else {
                    temp = (i / mid) + 1;
                }
                total += temp;
            }
            if (total <= h) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }
};