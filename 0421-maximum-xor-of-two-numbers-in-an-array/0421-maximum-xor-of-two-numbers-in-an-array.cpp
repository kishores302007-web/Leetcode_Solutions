class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxResult = 0;
        int mask = 0;
        for (int i = 30; i >= 0; --i) {
            mask |= (1 << i);
            int greedyTarget = maxResult | (1 << i);
            unordered_set<int> prefixes;
            for (int num : nums) {
                prefixes.insert(num & mask);
            }
            for (int prefix : prefixes) {
                if (prefixes.count(prefix ^ greedyTarget)) {
                    maxResult = greedyTarget; 
                    break; 
                }
            }
        }
        
        return maxResult;
    }
};