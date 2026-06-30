class Solution {
public:
    int hammingDistance(int x, int y) {
        int sol = x^y;
        int count = 0;
        while(sol>0){
            sol &= (sol-1);
            count++; 
        }
        return count;
    }
};