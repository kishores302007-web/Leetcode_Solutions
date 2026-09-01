class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> subarr;
        int sum = 0;
        int maxlen = 0;
        subarr[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 0) ? -1 : 1;
        
            if (subarr.find(sum) != subarr.end()) {
                int len = i - subarr[sum];
                maxlen = max(maxlen, len);
            } else {
                subarr[sum] = i;
            }
        }
        return maxlen;
    }
};