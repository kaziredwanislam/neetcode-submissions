class Solution {
public:
    bool isPresent(vector<int>nums,int num) {
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==num)return true;
        }
        return false;
    }

    bool isHappy(int n) {
        vector<int>nums;
        nums.push_back(n);
        while(true) {
            int curNum=n;
            int newNum=0;
            while(curNum>0) {
                int curDigit=curNum%10;
                curNum/=10;
                newNum+=curDigit*curDigit;
            }
            if(newNum==1)return true;
            if(isPresent(nums,newNum))return false;
            nums.push_back(newNum);
            n=newNum;
        }    
        return false;
    }
};
