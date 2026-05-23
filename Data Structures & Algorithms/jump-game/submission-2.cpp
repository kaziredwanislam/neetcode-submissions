#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int retChosenNextIndex(vector<int>&subNums,int curPos)
    {
        //cout<<"a"<<subNums.size()<<endl;
        for(int j=0;j<subNums.size();j++)
        {
            subNums[j]+=j;
        }
        int maxJump=subNums[0];
        int maxIndex=curPos+1;
        //cout<<maxIndex<<" "<<curPos<<endl;
        for(int j=1;j<subNums.size();j++){
            if(subNums[j]>maxJump)
            {
                maxJump=subNums[j];
                maxIndex=curPos+j+1;
            }
        }
        //cout<<"maxIndex: "<<maxIndex<<endl;
        return maxIndex;
    }
    bool canJump(vector<int>& nums) {
        int i=0;
        if(nums.size()==1)return true;
        while(true)
        {
            int maxJump=nums[i];
            if(maxJump==0)return false;
            if(i+maxJump>=nums.size()-1)return true;
            //cout<<i<<" "<<maxJump<<endl;
            vector<int>subNums(nums.begin()+i+1,nums.begin()+i+maxJump+1);
            //cout<<subNums.size()<<" bb"<<i+1<<"  "<<i+maxJump<<endl;
            int nextIndex=retChosenNextIndex(subNums,i);
            i=nextIndex;
            //break;
        }
    }
};