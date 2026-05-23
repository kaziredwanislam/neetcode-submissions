class Index{
    public:
    int x;
    int y;
};

class Solution {
public:
    bool isValidIndex(vector<vector<int>>&grid,Index index)
    {
        if(index.x<0 || index.y<0)return false;
        if(index.x>=grid.size()||index.y>=grid[0].size())return false;
        return true;
    }

    bool noFreshFruit(vector<vector<int>>&grid)
    {
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1){cout<<"Yes"<<endl;return false;}
            }
        }

        return true;
    }

    int getMaxTime(vector<vector<int>>&time)
    {
        int maxTime=time[0][0];
        for(int i=0;i<time.size();i++)
        {
            for(int j=0;j<time[0].size();j++)
            {
                if(time[i][j]>maxTime)maxTime=time[i][j];
            }
        }
        return maxTime;
    }

    void bfs(vector<vector<int>>&grid,vector<vector<int>>&time)
    {
        queue<Index>indexq;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    Index rotIndex;
                    rotIndex.x=i;
                    rotIndex.y=j;
                    indexq.push(rotIndex);
                    time[i][j]=0;
                }
            }
        }

        while(indexq.size()>0)
        {
            Index curIndex=indexq.front();
            //cout<<curIndex.x<<" xy "<<curIndex.y<<endl;
            indexq.pop();

            Index index1;
            index1.x=curIndex.x;
            index1.y=curIndex.y+1;
           // cout<<index1.x<<" "<<index1.y<<"   "<<isValidIndex(grid,index1)<<"  *  "<<grid[index1.x][index1.y]<<" "<<time[index1.x][index1.y]<<endl;
            if(isValidIndex(grid,index1)&&grid[index1.x][index1.y]==1 &&(time[index1.x][index1.y]==-1 || time[index1.x][index1.y]>time[curIndex.x][curIndex.y]+1))
            {
                //cout<<"hahahah"<<endl;
                indexq.push(index1);
                grid[index1.x][index1.y]=2;
                time[index1.x][index1.y]=time[curIndex.x][curIndex.y]+1;
            }

            Index index2;
            index2.x=curIndex.x;
            index2.y=curIndex.y-1;
            if(isValidIndex(grid,index2)&&grid[index2.x][index2.y]==1 &&(time[index2.x][index2.y]==-1 || time[index2.x][index2.y]>time[curIndex.x][curIndex.y]+1))
            {
                indexq.push(index2);
                grid[index2.x][index2.y]=2;
                time[index2.x][index2.y]=time[curIndex.x][curIndex.y]+1;
            }

            Index index3;
            index3.x=curIndex.x+1;
            index3.y=curIndex.y;
            if(isValidIndex(grid,index3)&&grid[index3.x][index3.y]==1 &&(time[index3.x][index3.y]==-1 || time[index3.x][index3.y]>time[curIndex.x][curIndex.y]+1))
            {
                indexq.push(index3);
                grid[index3.x][index3.y]=2;
                time[index3.x][index3.y]=time[curIndex.x][curIndex.y]+1;
            }

            Index index4;
            index4.x=curIndex.x-1;
            index4.y=curIndex.y;
            if(isValidIndex(grid,index4)&&grid[index4.x][index4.y]==1 &&(time[index4.x][index4.y]==-1 || time[index4.x][index4.y]>time[curIndex.x][curIndex.y]+1))
            {
                indexq.push(index4);
                grid[index4.x][index4.y]=2;
                time[index4.x][index4.y]=time[curIndex.x][curIndex.y]+1;
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>>time;
        int row=grid.size();
        int col=grid[0].size();
        //cout<<"col"<<col<<endl;
        for(int i=0;i<row;i++)
        {
            vector<int>t(col,-1);

            time.push_back(t);
        }
        
        //cout<<endl<<endl;
        bfs(grid,time);
        if(noFreshFruit(grid))
        {
            int requiredTime=getMaxTime(time);
            if(requiredTime>=0)return requiredTime;
            else return 0;
        }
        else return -1;
        
    }
};
