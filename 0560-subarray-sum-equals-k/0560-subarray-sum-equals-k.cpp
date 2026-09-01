class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> subb;
        int sum = 0;
        int count = 0;
        subb[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (subb.find(sum - k) != subb.end()) {
                count += subb[sum-k];
            }
            subb[sum]++;
        }
        return count;
    }
};