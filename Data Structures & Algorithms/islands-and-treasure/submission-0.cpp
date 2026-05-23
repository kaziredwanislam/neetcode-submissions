class Index
{
    public:
        int x;
        int y;
        int dis=0;
};

class Solution {
public:
    bool isValidIndex(vector<vector<int>>&grid,Index index)
    {
        if(index.x<0||index.y<0)return false;
        if(index.x>=grid.size()||index.y>=grid[0].size())return false;
        return true;
    }

    void bfs(vector<vector<int>>&grid,Index index)
    {
        if(isValidIndex(grid,index))
        {
            queue<Index>indexq;
            indexq.push(index);
            //int distance=1;
            while(indexq.size()>0)
            {
                Index curIndex=indexq.front();
                indexq.pop();
                Index index1;
                index1.x=curIndex.x;
                index1.y=curIndex.y+1;
                if(isValidIndex(grid,index1)&&grid[index1.x][index1.y]!=0&&grid[index1.x][index1.y]!=-1&&grid[index1.x][index1.y]>curIndex.dis+1)
                {
                    grid[index1.x][index1.y]=curIndex.dis+1;
                    index1.dis=curIndex.dis+1;
                    indexq.push(index1);
                }

                Index index2;
                index2.x=curIndex.x;
                index2.y=curIndex.y-1;
                if(isValidIndex(grid,index2)&&grid[index2.x][index2.y]!=0&&grid[index2.x][index2.y]!=-1&&grid[index2.x][index2.y]>curIndex.dis+1)
                {
                    grid[index2.x][index2.y]=curIndex.dis+1;
                    index2.dis=curIndex.dis+1;
                    indexq.push(index2);
                }

                Index index3;
                index3.x=curIndex.x+1;
                index3.y=curIndex.y;
                if(isValidIndex(grid,index3)&&grid[index3.x][index3.y]!=0&&grid[index3.x][index3.y]!=-1&&grid[index3.x][index3.y]>curIndex.dis+1)
                {
                    grid[index3.x][index3.y]=curIndex.dis+1;
                    index3.dis=curIndex.dis+1;
                    indexq.push(index3);
                }

                Index index4;
                index4.x=curIndex.x-1;
                index4.y=curIndex.y;
                if(isValidIndex(grid,index4)&&grid[index4.x][index4.y]!=0&&grid[index4.x][index4.y]!=-1&&grid[index4.x][index4.y]>curIndex.dis+1)
                {
                    grid[index4.x][index4.y]=curIndex.dis+1;
                    index4.dis=curIndex.dis+1;
                    indexq.push(index4);
                }
                //distance+=1;
                
            }
        }
    }

    void showGrid(vector<vector<int>>&grid)
    {
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)
                {
                    Index index;
                    index.x=i;
                    index.y=j;
                    index.dis=0;
                    bfs(grid,index);
                    //cout<<i<<" "<<j<<endl;
                    //showGrid(grid);
                }
            }
        }
    }
};
