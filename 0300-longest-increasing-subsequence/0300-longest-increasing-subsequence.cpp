class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int i =0; i<nums.size(); i++){
            int pos = lower_bound(res.begin(),res.end(),nums[i]) - res.begin();
            if(pos == res.size()){
                res.push_back(nums[i]);
            }
            else{
                res[pos] = nums[i];
            }
        }
        return res.size();
        
    }
};