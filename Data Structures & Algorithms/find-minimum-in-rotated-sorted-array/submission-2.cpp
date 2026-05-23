class Solution {
public:
    int findMin(vector<int> &nums) {
        int left=0;
        int right=nums.size()-1;
        if(nums[left]<nums[right])return nums[left];

        while(left<=right) {
            int mid=left+(right-left)/2;
            if(mid>0 && nums[mid]<nums[mid-1])return nums[mid];

            if(mid<nums.size()-1 && nums[mid]>nums[mid+1])return nums[mid+1];

            if(nums[mid]>nums[left]) left=mid+1;
            else {
                right =mid-1;
            }
        }
        return nums[0];
        
    }
};
