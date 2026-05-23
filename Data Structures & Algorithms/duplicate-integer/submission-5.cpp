class Solution {
public:
    bool isPresent(vector<vector<int>>&hashAra,int n,int index) {
        for(int i=0;i<hashAra[index].size();i++) {
            if(hashAra[index][i]==n)return true;
        }
        return false;
    }

    bool hasDuplicate(vector<int>& nums) {
        if(nums.size()==0)return false;
        vector<vector<int>>hashAra(10,vector<int>());
        for(int i=0;i<nums.size();i++)
        {
            int index;
            if(nums[i]<0)index=(nums[i]*(-1))%10;
            else index=nums[i]%10;
            if(isPresent(hashAra,nums[i],index))return true;
            //int index=nums[i]%10;
            hashAra[index].push_back(nums[i]);
        }
        return false;
    }

};