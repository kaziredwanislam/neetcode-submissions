class HashMap {
    vector<vector<int>>hashMap;
    int size;
public:
    HashMap(int s) {
        size=s;
        for(int i=0;i<size;i++) {
            vector<int>v;
            hashMap.push_back(v);
        }
    }

    void insert(int num) {
        if(!isPresent(num)) {
            int index=abs(num)%size;
            hashMap[index].push_back(num);
        }
    }

    bool isPresent(int num) {
        int index=abs(num)%size;
        for(int i=0;i<hashMap[index].size();i++) {
            if(hashMap[index][i]==num)return true;
        }
        return false;
    }
};

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        HashMap hashMap(10);
        for(int i=0;i<nums.size();i++) {
            if(hashMap.isPresent(nums[i])) return  true;
            hashMap.insert(nums[i]);
        }
        return false;
    }
};