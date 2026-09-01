class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int,int> map;
        for(char i : magazine){
            map[i]++;
        }
         for(char i : ransomNote){
            if(map[i] == 0){
                return false;     
            }
            map[i]--;
        }
        return true;
    }
};