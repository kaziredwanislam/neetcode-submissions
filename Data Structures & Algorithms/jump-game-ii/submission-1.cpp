class Solution {
public:
    int retNextIndex(vector<int>&subNums,int pos)
    {
        for(int j=1;j<subNums.size();j++)subNums[j]+=j;
        int maxJump=subNums[0];
        int maxIndex=pos+1;
        for(int j=1;j<subNums.size();j++)
        {
            if(subNums[j]>maxJump)
            {
                maxJump=subNums[j];
                maxIndex=j+pos+1;
            }
        }
        return maxIndex;
    }

    int jump(vector<int>& nums) {
        int totalJump=1;
        int pos=0;
        if(nums.size()==1)return 0;
        while(true)
        {
            int maxJump=nums[pos];
            if(pos+maxJump>=nums.size()-1)return totalJump;
            vector<int>subNums(nums.begin()+pos+1,nums.begin()+pos+maxJump+1);
            pos=retNextIndex(subNums,pos);
            totalJump++;
        }
    }
};
