class Solution {
public:
    int maxArea(vector<int>& height) {

        int right = height.size()-1;
        int left = 0;
        int solution = 0;

        while(right>left){
            int h = min(height[left], height[right]);
            int w = right - left;
            int area = h*w;

            solution = max(solution, area);

            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }  
        } 
    return solution;
    }
};