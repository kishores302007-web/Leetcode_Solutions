class Solution {
public:
    int smallestEvenMultiple(int n){
        //bsce condition
        if(n <= 0){
            return 0;
        }
        //check odd or even and return 
        if((n % 2) == 0){
            return n;
        }
        else{
            return n*2;
        }

        
    }
};