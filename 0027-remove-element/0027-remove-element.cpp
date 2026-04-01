class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;

        int count = 0;

            for (int j=0; j<nums.size(); j++){
                if(nums[j] != val){
                    nums[count] = nums[j];
                    ++count;
                }
            }
        return count;
        
    }
};