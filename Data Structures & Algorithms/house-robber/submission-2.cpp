class Solution {
public:
    int rob(vector<int>& nums) {
        int tot_house=nums.size();
        if(tot_house==1)return nums[0];
        if(tot_house==2)return max(nums[0],nums[1]);
        vector<int>amount;
        for(int i=0;i<nums.size();i++)
        {
            amount.push_back(0);
        }
        amount[tot_house-1]=nums[tot_house-1];
        amount[tot_house-2]=nums[tot_house-2];
        amount[tot_house-3]=nums[tot_house-1]+nums[tot_house-3];
        int house=tot_house-4;

        while(house>=0)
        {
            int max_gain=max(amount[house+2],amount[house+3]);
            amount[house]=max_gain+nums[house];
            house--;
        }
        return max(amount[0],amount[1]);
    }
};
