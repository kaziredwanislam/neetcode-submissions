class Solution {
public:
    void showV(vector<vector<int>>&grid)
    {
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)cout<<grid[i][j]<<" ";
            cout<<endl;
        }
    }

    int max(int a,int b)
    {
        if(a>=b)return a;
        return b;
    }

    int max(int a,int b,int c)
    {
        if(a>=b && a>=c)return a;
        if(b>=c && b>=a)return b;
        return c;
    }

    int maxProfit(vector<int>& prices) {
        int totDays=prices.size();
        if(prices.size()==1)return 0;
        vector<vector<int>>grid;
        for(int i=0;i<totDays;i++)
        {
            vector<int>v(totDays,0);
            grid.push_back(v);
        }
        for(int i=1;i<totDays;i++)
        {
            grid[0][i]=max(prices[i]-prices[0],grid[0][i-1]);
        }
        if(totDays==2)return grid[0][totDays-1];
        grid[1][1]=grid[0][1];
        //grid[1][2]=max(grid[0][2],0);
        for(int i=2;i<totDays;i++)
        {
            grid[1][i]=max(prices[i]-prices[1],grid[1][i-1],grid[0][i]);
        }
        if(totDays==3)return grid[1][totDays-1];

        grid[2][1]=grid[1][1];
        grid[2][2]=max(grid[2][1],grid[1][2]);
        //grid[2][3]=max(grid[2][2],grid[1][3],0);
        for(int i=3;i<totDays;i++)
        {
            grid[2][i]=max(prices[i]-prices[2],grid[2][i-1],grid[1][i]);
        }
        if(totDays==4)return grid[2][totDays-1];

        for(int i=3;i<totDays;i++)
        {
            for(int j=0;j<=i;j++)
            {
                grid[i][j]=grid[i-1][j];
            }
            for(int j=i+1;j<totDays;j++)
            {
                grid[i][j]=max(prices[j]-prices[i]+grid[i-2][i-2],grid[i][j-1],grid[i-1][j]);
            }
        }

        //showV(grid);
        return grid[totDays-1][totDays-1];
    }
};
