class Solution {
public:
    int showGrid(vector<vector<int>>&grid)
    {
        int length1=grid.size();
        int length2=grid[0].size();
        for(int i=0;i<length1;i++)
        {
            for(int j=0;j<length2;j++)cout<<grid[i][j]<<" ";
            cout<<endl;
        }
    }

    int max(int a,int b)
    {
        if(a>b)return a;
        return b;
    }
    int max(int a,int b,int c)
    {
        if(a>=b && a>=c)return a;
        if(b>=a && b>=c)return b;
        return c;
    }

    int longestCommonSubsequence(string text1, string text2) {
        int length1=text1.size();
        int length2=text2.size();
        vector<vector<int>>grid;

        for(int i=0;i<length1;i++)
        {
            vector<int>v(length2,0);
            grid.push_back(v);
        }


        for(int i=0;i<length2;i++)
        {
            if(text1[0]==text2[i])grid[0][i]=1;
            if(i>0 && grid[0][i-1]==1)grid[0][i]=1;
        }
        for(int i=0;i<length1;i++)
        {
            if(text2[0]==text1[i])grid[i][0]=1;
            if(i>0 && grid[i-1][0]==1)grid[i][0]=1;
        }

        for(int i=1;i<length1;i++)
        {
            for(int j=1;j<length2;j++)
            {
                if(text1[i]==text2[j])
                {
                    grid[i][j]=max(grid[i-1][j-1]+1,grid[i-1][j],grid[i][j-1]);
                }
                else
                {
                    grid[i][j]=max(grid[i-1][j],grid[i][j-1]);
                }
            }
        }

        //showGrid(grid);
        return grid[length1-1][length2-1];
    }
};