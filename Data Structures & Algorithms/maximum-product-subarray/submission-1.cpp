class Solution {
public:
    int max(int a,int b,int c) {
        if(a>=b && a>=c)return a;
        if(b>=c && b>=a)return b;
        return c;
    }

    int min(int a,int b,int c) {
        if(a<=b && a<=c)return a;
        if(b<=c && b<=a)return b;
        return c;
    }

    int maxProduct(vector<int>& nums) {
        vector<int>maxVals;
        vector<int>minVals;

        for(int i=0;i<nums.size();i++) {
            maxVals.push_back(nums[i]);
            minVals.push_back(nums[i]);
        }

        for(int i=1;i<nums.size();i++) {
            maxVals[i]=max(maxVals[i-1]*nums[i],minVals[i-1]*nums[i],nums[i]);
            minVals[i]=min(maxVals[i-1]*nums[i],minVals[i-1]*nums[i],nums[i]);
        }

        int maxVal=nums[0];
        for(int i=0;i<nums.size();i++) {
            if(maxVals[i]>maxVal)maxVal=maxVals[i];
        }
        return maxVal;
    }
};
