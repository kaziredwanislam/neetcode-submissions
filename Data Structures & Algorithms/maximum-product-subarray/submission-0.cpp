class Solution {
public:

    int maxVal(vector<int>&nums)
    {
        int maxVal=nums[0];
        for(int n:nums)
        {
            if(n>maxVal)maxVal=n;
        }
        return maxVal;
    }

    int maxProduct(vector<int>& nums) {
        int maxProduct=maxVal(nums);
        for(int i=0;i<nums.size();i++)
        {
            int product=nums[i];
            int curMaxProduct=product;
            for(int j=i+1;j<nums.size();j++)
            {
                product=product*nums[j];
                if(product>curMaxProduct)curMaxProduct=product;
            }
            if(curMaxProduct>maxProduct)maxProduct=curMaxProduct;
        }
        return maxProduct;
    }
};
