class HashMap{
    vector<vector<int>>v;
    int size;
public:
    HashMap()
    {
        size=10;
        for(int i=0;i<size;i++)
        {
            vector<int>vv;
            v.push_back(vv);
        }
    }

    void insert(int num)
    {
        int index=num%size;
        if(!isPresent(num))v[index].push_back(num);
    }

    bool isPresent(int num)
    {
        int index=num%size;
        vector<int>vv=v[index];
        for(int n: vv)
        {
            if(n==num)return true;
        }
        return false;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        HashMap myMap;
        for(int n:nums)
        {
            if(!myMap.isPresent(n))
            {
                myMap.insert(n);
            }
            else return n;
        }
    }
};

