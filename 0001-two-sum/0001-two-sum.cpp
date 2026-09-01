class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> val;
        for(int i = 0; i <nums.size(); i++){
            int temp = target - nums[i];
            if(val.find(temp) != val.end( )){
                return{val[temp],i};
            }
            val[nums[i]] = i;
        }
        return {};
    }
};