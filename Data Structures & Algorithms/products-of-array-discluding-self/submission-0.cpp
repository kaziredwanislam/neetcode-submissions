class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>products(nums.size(),1);
        for(int i=0;i<nums.size();i++)
        {
            int product=1;
            for(int j=0;j<nums.size();j++)
            {
                if(i==j)continue;
                product*=nums[j];
            }
            products[i]=product;
        }
        return products;
    }
};
