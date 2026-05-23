class Solution {
public:
    int findMin(vector<int> &nums) {
        int left=0;
        int right=nums.size()-1;
        if(nums[left]<nums[right])return left;

        while(left<=right) {
            int mid=left+(right-left)/2;
            if(mid>0 && nums[mid]<nums[mid-1])return mid;

            if(mid<nums.size()-1 && nums[mid]>nums[mid+1])return mid+1;

            if(nums[mid]>nums[left]) left=mid+1;
            else {
                right =mid-1;
            }
        }
        return 0;
        
    }

    int binarySearch(vector<int>&nums,int left,int right,int target) {
        //cout<<nums[left]<<" "<<nums[right]<<" "<<target<<endl;
        while(left<=right) {
            int mid=left+(right-left)/2;
            if(nums[mid]==target) {
                return mid;
            }
            else if(nums[mid]<target) {
                left=mid+1;
            }
            else {
                right=mid-1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        if(nums[0]==target)return 0;

        int left=0;
        int right=nums.size()-1;
        int minIndex=findMin(nums);
        //cout<<minIndex<<" "<<nums[minIndex]<<endl;
        if(nums[minIndex]==target)return minIndex;
        if(minIndex==0)return binarySearch(nums,left,right,target);
        if(nums[left]<target) return binarySearch(nums,left,minIndex-1,target);
        return binarySearch(nums,minIndex,right,target);
    }
};
