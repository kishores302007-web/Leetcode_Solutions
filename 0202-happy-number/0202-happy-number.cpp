class Solution {
public:
    int sum_sol(int n) {
        int dig = 0;
        while (n > 0) {
            int res = n % 10;
            dig += res * res;
            n = n / 10;
        }
        return dig;
    }
    bool isHappy(int n) {
        set<int> seen;
        while (n != 1) {
            if (seen.count(n)) {
                return false;
            }
        seen.insert(n);
        n = sum_sol(n);
        }
        return true;
    }
};