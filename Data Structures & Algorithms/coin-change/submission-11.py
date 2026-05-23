class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount==0:
            return 0
        coins.sort()
        tot_coins=len(coins)
        req=[[100000 for _ in range(amount+1)] for _ in range(tot_coins)]

        for i in range(1,amount+1):
            if i%coins[0]==0:
                req[0][i]=i//coins[0]

        for i in range(1,tot_coins):
            for j in range(1,amount+1):
                if j<coins[i]:
                    req[i][j]=req[i-1][j]
                else:
                    if j%coins[i]==0:
                        req[i][j]=min(req[i-1][j],j//coins[i])
                    else:
                        req[i][j]=min(req[i-1][j],req[i][j-coins[i]]+1)

        #print(req)
        
        if req[tot_coins-1][amount]==100000:
            return -1
        return req[tot_coins-1][amount]