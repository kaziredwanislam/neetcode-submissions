class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++) {
            for(int j=i+1;j<nums.size()-1;j++) {
                int sum=nums[i]+nums[j];
                int target=-sum;
                int begin=j+1;
                int end=nums.size()-1;
                
                while(begin<=end) {
                    int mid=(begin+end)/2;
                    if(nums[mid]==target) {
                        vector<int>v({nums[i],nums[j],nums[mid]});
                        res.insert(v);
                        break;
                    }
                    else if(nums[mid]<target) {
                        begin=mid+1;
                    }
                    else {
                        end=mid-1;
                    }
                }

            }
        }

        for(vector<int>v:res) {
            ans.push_back(v);
        }

        return ans;
    }
};
