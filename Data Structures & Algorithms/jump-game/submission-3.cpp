class Solution {
public:
    bool canJump(vector<int>& nums) {
       vector<bool>reachable(nums.size(),false);
       int n=nums.size();
       reachable[n-1]=true;

       for(int i=n-2;i>=0;i--) {
            int maxAchievedInd=min(n-1,i+nums[i]);
            for(int j=i+1;j<=maxAchievedInd;j++) {
                if(reachable[j]==true) {
                    reachable[i]=true;
                    break;
                }
                
            }
            //cout<<i<<" "<<reachable[i]<<endl;
       } 

       return reachable[0];
    }
};
