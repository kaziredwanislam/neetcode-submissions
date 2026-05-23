class Solution {
public:
 int max(int a,int b) {
        if(a>=b)return a;
        return b;
    }
    int robVal(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
       vector<int>robbing(nums.size(),0);
       robbing[nums.size()-1]=nums[nums.size()-1];
       //cout<<nums[nums.size()-1]<<" "<<nums[nums.size()-2]<<endl;
       robbing[nums.size()-2]=max(nums[nums.size()-1],nums[nums.size()-2]);

       for(int i=nums.size()-3;i>=0;i--) {
            robbing[i]=max( robbing[i+1],nums[i]+robbing[i+2]);
       } 

       

       return robbing[0];
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>v;
        v.assign(nums.begin(),nums.begin()+n-1);
        int val1=robVal(v);
        v.assign(nums.begin()+1,nums.begin()+n);
        int val2=robVal(v);
        return max(val1,val2);
    }
};
