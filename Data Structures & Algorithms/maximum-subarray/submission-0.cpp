class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int>subarraySum;
        for(int i=0;i<nums.size();i++)
        {
            subarraySum.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            int maxSum=subarraySum[i];
            int curSum=subarraySum[i];
            for(int j=i+1;j<nums.size();j++)
            {
                curSum+=nums[j];
                if(curSum>maxSum)maxSum=curSum;
                if(curSum<=0)break;
            }
            subarraySum[i]=maxSum;
        }
        int maxSubarraySum=subarraySum[0];
        for(int j=1;j<subarraySum.size();j++)
        {
            if(maxSubarraySum<subarraySum[j])
            {
                maxSubarraySum=subarraySum[j];
            }
        }
        return maxSubarraySum;
    }
};
