class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>threeSums;
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                for(int k=j+1;k<nums.size();k++)
                {
                    if(nums[i]+nums[j]+nums[k]==0)
                    {
                        vector<int>threeSum;
                        threeSum.push_back(nums[i]);
                        threeSum.push_back(nums[j]);
                        threeSum.push_back(nums[k]);
                        threeSums.insert(threeSum);
                    }
                }
            }
        }
        for(vector<int>v:threeSums)
        {
            res.push_back(v);
        }
        return res;
    }
};
