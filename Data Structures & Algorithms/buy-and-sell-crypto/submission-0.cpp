class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=prices[0];
        int maxProfit=0;
        for(int i=0;i<prices.size();i++) {
            if(prices[i]<minPrice)minPrice=prices[i];
            int curProfit=prices[i]-minPrice;
            if(curProfit>maxProfit)maxProfit=curProfit;
        }
        return maxProfit;
    }
};
