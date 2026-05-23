class Solution {
public:
    int findLis(vector<int>&nums,vector<int>&LisList,int index) {
        int curNum=nums[index];
        int Lis=1;
        for(int i=index+1;i<LisList.size();i++) {
            if(nums[index]==nums[i] && Lis<=LisList[i]) {
                Lis=LisList[i];
            }
            else if(nums[index]<nums[i] && Lis<=LisList[i]) {
                Lis=LisList[i]+1;
            }
        }
        return Lis;

    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int>LisList(nums.size(),1);
        for(int i=nums.size()-2;i>=0;i--) {
        
                LisList[i]=findLis(nums,LisList,i);
           
        }

        int maxLis=1;
        for(int i=0;i<LisList.size();i++) {
            cout<<LisList[i]<<" ";
            if(LisList[i]>maxLis)maxLis=LisList[i];
        }
        return maxLis;
    }
};
