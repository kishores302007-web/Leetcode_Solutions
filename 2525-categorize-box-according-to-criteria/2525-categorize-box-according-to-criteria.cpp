class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {

        long long volume = 1LL* length*width*height;
        int h=0;int b=0;
        if(volume >= 1000000000 || length >= 10000 || width >= 10000 || height >= 10000){
            b++;
        }
        if(volume >= 1,000,000,000){
            b++;
        }
        if(mass >= 100){
           h++;
        }

        if((h+b) == 2){
            return "Both";
        }else{
            if(((h == 0)&&(b == 0))){
                return "Neither";
            }
            else if(h == 1){
                return "Heavy";
            }
            else {
                return "Bulky";
            }
        }
        
    }
};