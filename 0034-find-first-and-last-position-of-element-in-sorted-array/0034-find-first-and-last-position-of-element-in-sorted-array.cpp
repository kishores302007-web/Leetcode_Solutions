class Solution {
int firstindex(vector < int>& nums,int target){
// to find initial index of starting element
    int first = -1;
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            first = mid;
            right = mid - 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return first;
} 

int lastindex(vector < int>& nums, int target) {
// to find the last index of the target
    int last = -1;
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            last = mid;
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return last;
}
public:
    vector<int> searchRange(vector<int>& nums, int target){
        vector<int> ans;
        ans.push_back(firstindex(nums,target));
        ans.push_back(lastindex(nums,target));
        return ans;
    }
};



  
