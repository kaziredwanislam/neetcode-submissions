class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>res;
        for(int i=0;i<cost.size();i++)
        {
            res.push_back(0);
        }
        int size=cost.size();
        res[size-1]=cost[size-1];
        res[size-2]=cost[size-2];
        for(int i=size-3;i>=0;i--)
        {
            int nextCost=min(res[i+1],res[i+2]);
            res[i]=cost[i]+nextCost;
        }
        return min(res[0],res[1]);
    }
};
