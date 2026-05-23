class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)return 0;
        sort(coins.begin(),coins.end());
        int tot_coins=coins.size();
        vector<vector<int>>dp(tot_coins,vector<int>(amount+1,100000000));
        for(int i=1;i<=amount;i++) {
            if(i%coins[0]==0) {
                int req_coin=i/coins[0];
                dp[0][i]=req_coin;
            }
        }

        for(int i=1;i<tot_coins;i++) {
            for(int j= 1;j<=amount;j++) {
                if(j<coins[i]) {
                    dp[i][j]=dp[i-1][j];
                    //cout<<j<<" "<<coins[i]<<endl;
                }
                else {
                    if(j%coins[i]==0) {
                        dp[i][j]=min(j/coins[i],dp[i-1][j]);
                    }
                    else {
                        
                            dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i]]+1);
          

                    }
                }

                
            }
        }

        /*for(int i=0;i<tot_coins;i++) {
            for(int j=0;j<=amount;j++) {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
       
        //cout<<tot_coins-1<<" "<<amount<<endl;
        if( dp[tot_coins-1][amount]==100000000)return -1;
        return dp[tot_coins-1][amount];
    }
};
