class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int h = accumulate(weights.begin(), weights.end(), 0);
        int ans = h;
        while (l <= h) {
            int mid = l + (h - l) / 2;

            int r_d = 1;
            int c_w = 0;
            for (int w : weights) {
                if (c_w + w > mid) {
                    r_d++;
                    c_w = 0;
                }
                    c_w += w;
                
            }
            if (r_d <= days) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};