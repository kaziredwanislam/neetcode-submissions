class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==1)return 1;

        int len=nums.size();
        vector<int>ans(nums.size(),1);

        for(int i=len-2;i>=0;i--) {
            for(int j=i+1;j<len;j++) {
                if(nums[j]>nums[i] && ans[j]>=ans[i])  {
                    ans[i]=ans[j]+1;
                }
            }
        }

        int lis=ans[0];
        for(int i=1;i<ans.size();i++) {
            if(ans[i]>lis)lis=ans[i];
        }
        return lis;
    }
};
