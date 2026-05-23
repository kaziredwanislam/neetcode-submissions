class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxVal=nums[0];

        for(int i=0;i<nums.size();i++) {
            int curSum=nums[i];
            if(curSum>maxVal)maxVal=curSum;
            for(int j=i+1;j<nums.size();j++) {
                curSum+=nums[j];
                if(curSum>maxVal){
                    maxVal=curSum;
                   
                
                 }
                if(curSum<=0)break;
            }
            
           
        }

        return maxVal;
    }
};
