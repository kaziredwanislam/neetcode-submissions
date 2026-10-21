class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int valCount = 0;
        int len=nums.size();
        for (int i=0;i<nums.size();i++) {
            if(nums[i]==val)valCount++;
        }

        for(int i=0;i<valCount;i++) {
            erase(nums,val);
        }

        return len-valCount;
    }
};