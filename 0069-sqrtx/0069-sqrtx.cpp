class Solution {
public:
    int mySqrt(int x) {
        int l = 0, h = x, ans = 0;
        if((x==0)||(x==1)) return x;

        while( l<= h){
            int m = l+(h-l)/2;
            if(m <= x/m){
                //ans = m;
                l = m + 1;
            }
            else{
                h = m - 1;
            }
        }
        return h;
    }
};