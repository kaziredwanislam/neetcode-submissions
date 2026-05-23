class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        vector<vector<int>>v;
        for(int i=0;i<nums.size();i++)
        {
            vector<int>vv;
            //vv.push_back(0);
            v.push_back(vv);
        }
        int size=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            int val=nums[i];
            int ival=val;
            if(val<0)ival=val*(-1);
            int index=ival%size;
            for(int j=0;j<v[index].size();j++)
            {
                if(v[index][j]==val){return true;}
            }
            v[index].push_back(val);
        }
        return false;
    }
};
