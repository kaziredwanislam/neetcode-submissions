class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)return 0;
        sort(coins.begin(),coins.end());
        int totCoins=coins.size();
        vector<vector<int>>grids(totCoins+1,vector<int>(amount+1,amount+1));
        for(int i=0;i<=totCoins;i++)grids[i][0]=0;
        
        for(int i=1;i<=totCoins;i++) {
            for(int j=1;j<=amount;j++) {
                grids[i][j]=grids[i-1][j];
                if(j>=coins[i-1]) {
                    grids[i][j]=min(grids[i][j],grids[i][j-coins[i-1]]+1);
                }
            }
        }

        /*for(int i=0;i<=totCoins;i++) {
            for(int j=0;j<=amount;j++) {
                cout<<grids[i][j]<<" ";
            }
            cout<<endl;
        }*/

        if(grids[totCoins][amount]>amount
        )return -1;
        return grids[totCoins][amount];
    }
};
