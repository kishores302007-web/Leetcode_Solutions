#include <vector>

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        ans.reserve(nums.size());
        
        for (int x : nums) {
            if (x % 2 == 0) {
                ans.push_back(-1);
            } else {
                ans.push_back(x ^ ((x + 1) & ~x) >> 1);
            }
        }
        
        return ans;
    }
};
