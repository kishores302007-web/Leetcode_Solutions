class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> sub;
        int maxl = 0;
        int current = 0;
        for (int i = 0; i < s.size(); i++) {
            if (sub.find(s[i]) != sub.end()) {
                current = max(current, sub[s[i]] + 1);
            }
            sub[s[i]] = i;
            int len = i - current + 1;
            maxl = max(len, maxl);
        }
        return maxl;
    }
};