class Solution {
public:
    int findMin(vector<int> &nums) {
        int firstIndex=0;
        int lastIndex=nums.size()-1;
        int midIndex=(firstIndex+lastIndex)/2;
        while(firstIndex<lastIndex) {
        cout<<firstIndex<<" "<<midIndex<<" "<<nums[midIndex]<<endl;
         if(nums[firstIndex]<=nums[midIndex] && nums[midIndex]<=nums[lastIndex]) {
            cout<<"Returning: "<<nums[firstIndex]<<endl; 
            return nums[firstIndex];
         }
         
         if(nums[firstIndex]<=nums[midIndex]) {
            firstIndex=midIndex+1;
         }

         if(nums[firstIndex]>nums[midIndex]){
            firstIndex++;
            
         }
            midIndex=(firstIndex+lastIndex)/2;
        }
        cout<<"Returning midIndex: "<<midIndex<<endl;
        return nums[midIndex];
    }
};
