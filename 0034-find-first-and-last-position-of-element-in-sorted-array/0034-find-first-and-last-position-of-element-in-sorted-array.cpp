class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;int last = -1;
        int left = 0; int right = nums.size()-1;

// to find initial index of starting element

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                first = mid;
                right = mid - 1;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

// to find the last index of the target

        left = 0; right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                last = mid;
                left = mid + 1;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return {first,last};
    }
};