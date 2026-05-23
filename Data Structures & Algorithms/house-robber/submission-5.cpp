class Solution {
public:
    int max(int a,int b) {
        if(a>=b)return a;
        return b;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
       vector<int>robbing(nums.size(),0);
       robbing[nums.size()-1]=nums[nums.size()-1];
       //cout<<nums[nums.size()-1]<<" "<<nums[nums.size()-2]<<endl;
       robbing[nums.size()-2]=max(nums[nums.size()-1],nums[nums.size()-2]);

       for(int i=nums.size()-3;i>=0;i--) {
            robbing[i]=max( robbing[i+1],nums[i]+robbing[i+2]);
       } 

       for(int i=0;i<robbing.size();i++) {
        cout<<robbing[i]<<" ";
       }
       cout<<endl;

       return robbing[0];
    }
};
