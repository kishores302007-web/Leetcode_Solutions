class Solution {
public:
    bool wordPattern(string p, string s) {
        stringstream ss(s);
        vector<string> words;
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        if (words.size() != p.size()) {
            return false;
        }

        unordered_map<char, int> map1;
        unordered_map<string, int> map2;
        for (int i = 0; i < p.size(); i++) {
            if (map1.find(p[i]) == map1.end()) {
                map1[p[i]] = i;
            }
            if (map2.find(words[i]) == map2.end()) {
                map2[words[i]] = i;
            }
            if (map1[p[i]] != map2[words[i]]) {
                return false;
            }
        }
        return true;
    }
};