class Solution {
public:
    int findMinIndex(vector<int> &nums) {
        int firstIndex=0;
        int lastIndex=nums.size()-1;
        int midIndex=(firstIndex+lastIndex)/2;
        while(firstIndex<lastIndex) {
        //cout<<firstIndex<<" "<<midIndex<<" "<<nums[midIndex]<<endl;
         if(nums[firstIndex]<=nums[midIndex] && nums[midIndex]<=nums[lastIndex]) {
            //cout<<"Returning: "<<nums[firstIndex]<<endl; 
            return firstIndex;
         }
         
         else if(nums[firstIndex]<=nums[midIndex]) {
            firstIndex=midIndex+1;
         }

         else if(nums[firstIndex]>nums[midIndex]){
            
            firstIndex++;
            lastIndex=midIndex+1;
         }
            midIndex=(firstIndex+lastIndex)/2;
        }
        //cout<< firstIndex<<" "<<midIndex<<" "<<lastIndex<<endl;
        return midIndex;
    }

    int search(vector<int>& nums, int target) {
        
        int minIndex=findMinIndex(nums);
        cout<<"MinIndex: "<<minIndex<<endl;
        int midIndex=0;
        if(minIndex>0 && nums[0]<=target && nums[minIndex-1]>=target) {
            int firstIndex=0;
            int lastIndex=minIndex-1;
             midIndex=(firstIndex+lastIndex)/2;
            while(firstIndex<lastIndex) {
                 //midIndex=(firstIndex+lastIndex)/2;
                if(nums[midIndex]==target)return midIndex;
                else if(nums[midIndex]<target) {
                    firstIndex=midIndex+1;
                }
                else {
                    lastIndex=midIndex;
                }
                midIndex=(firstIndex+lastIndex)/2;
            }
        }

        else {
            int firstIndex=minIndex;
            int lastIndex=nums.size()-1;
             midIndex=(firstIndex+lastIndex)/2;
            while(firstIndex<lastIndex) {
               
                if(nums[midIndex]==target)return midIndex;
                else if(nums[midIndex]<target) {
                    firstIndex=midIndex+1;
                }
                else {
                    lastIndex=midIndex;
                }
                midIndex=(firstIndex+lastIndex)/2;
            }
        }
        if(nums[midIndex]==target)return midIndex;
        return -1;
    }
};
