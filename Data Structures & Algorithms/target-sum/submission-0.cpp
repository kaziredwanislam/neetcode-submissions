class Solution {
public:
    void addSub (vector<int>&nums,int sum,int targetSum,int index,int &totalWays)
    {
        if(index>=nums.size())
        {
            if(sum==targetSum)totalWays++;
        }
        else
        {
            int newSum=sum+nums[index];
            addSub(nums,newSum,targetSum,index+1,totalWays);
            newSum=sum-nums[index];
            addSub(nums,newSum,targetSum,index+1,totalWays);
        }
        
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int totalWays=0;
        addSub(nums,0,target,0,totalWays);
        return totalWays;
    }
};
