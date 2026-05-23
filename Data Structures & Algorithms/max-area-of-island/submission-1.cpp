class Index
{
    public:
    int row;
    int col;
};

class Solution {
public:
    bool isValidIndex(vector<vector<int>>&grid,Index index)
    {
        if(index.row<0 || index.col<0)return false;
        int totRow=grid.size();
        int totCol=grid[0].size();
        if(index.row>=totRow || index.col>=totCol)return false;
        return true;
    }
    int retIslandsize(vector<vector<int>>&grid,int marker,Index index)
    {
        queue<Index>islandq;
        islandq.push(index);
        grid[index.row][index.col]=marker;
        int islandSize=0;
        while(islandq.size()>0)
        {
            Index curIndex=islandq.front();
            islandq.pop();
            islandSize+=1;
            cout<<"y "<<curIndex.row<<" "<<curIndex.col<<endl;
            //grid[curIndex.row][curIndex.col]=marker;
            Index newIndex1;
            newIndex1.row=curIndex.row-1;
            newIndex1.col=curIndex.col;
            if(isValidIndex(grid,newIndex1) && grid[newIndex1.row][newIndex1.col]==1)
            {
                islandq.push(newIndex1);
                grid[newIndex1.row][newIndex1.col]=marker;
            }

            Index newIndex2;
            newIndex2.row=curIndex.row+1;
            newIndex2.col=curIndex.col;
            if(isValidIndex(grid,newIndex2)&& grid[newIndex2.row][newIndex2.col]==1)
            {
                islandq.push(newIndex2);
                grid[newIndex2.row][newIndex2.col]=marker;
            }

            Index newIndex3;
            newIndex3.row=curIndex.row;
            newIndex3.col=curIndex.col+1;
            if(isValidIndex(grid,newIndex3)&&grid[newIndex3.row][newIndex3.col]==1)
            {
                islandq.push(newIndex3);
                grid[newIndex3.row][newIndex3.col]=marker;
            }

            Index newIndex4;
            newIndex4.row=curIndex.row;
            newIndex4.col=curIndex.col-1;
            if(isValidIndex(grid,newIndex4)&& grid[newIndex4.row][newIndex4.col]==1)
            {
                islandq.push(newIndex4);
                grid[newIndex4.row][newIndex4.col]=marker;
            }

        }
        cout<<endl;
        return islandSize;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int marker=2;
        int hasOne=0;
        int totalIsland=0;
        int maxArea=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1){
                    totalIsland++;
                    Index index;
                    index.row=i;
                    index.col=j;
                    int area=retIslandsize(grid,marker,index);
                    if(area>maxArea)maxArea=area;
                }
            }
        }
        return maxArea;
    }
    
};
