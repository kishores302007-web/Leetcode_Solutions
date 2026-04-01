class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nums1_size = m-1;
        int nums2_size = n-1;
        int final_size = m+n-1;

        while((nums1_size >= 0) && (nums2_size >= 0)){
            if(nums1[nums1_size] > nums2[nums2_size]){
                nums1[final_size] = nums1[nums1_size];
                nums1_size--;
            }else{
                nums1[final_size] = nums2[nums2_size];
                nums2_size--;
            }
            final_size--;
        }

            while(nums2_size >= 0){
                nums1[final_size] = nums2[nums2_size];
                nums2_size--;
                final_size--;

            }
        
    }
};