class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int right = nums.size();
        int left = 0;
        sort(nums.begin(), nums.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};