class Solution:
    def climbStairs(self, n: int) -> int:
        stairs=[0 for _ in range(n)]
        if n==1:
            return 1
        if n==2:
            return 2
        stairs[n-1]=1
        stairs[n-2]=2

        for i in range(n-3,-1,-1):
            stairs[i]=stairs[i+1]+stairs[i+2]
        
        #print(stairs)
        return stairs[0]
