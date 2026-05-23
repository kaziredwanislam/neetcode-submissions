class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n=len(cost)
        if n==1:
            return cost[0]
        if n==2:
            return min(cost[0],cost[1])

        tot_cost=[0 for _ in range(n)]
        tot_cost[-1]=cost[-1]
        tot_cost[-2]=cost[-2]

        for i in range(n-3,-1,-1):
            tot_cost[i]=min(tot_cost[i+1],tot_cost[i+2])+cost[i]
        
        return min(tot_cost[0],tot_cost[1])
        