class Index {
public:
    int row;
    int col;
    Index() {

    }
    Index(int r,int c) {
        row=r;
        col=c;
    }
};


class Solution {
public:
    bool isValidIndex(vector<vector<char>>& grid,Index index) {
        int totRow=grid.size();
        int totCol=grid[0].size();

        if(index.row<0 || index.row>=totRow)return false;
        if(index.col<0 || index.col>=totCol)return false;
        return true;
    }
    
    void bfs(vector<vector<char>>& grid,int row,int col) {
        stack<Index>indexList;
        Index ob;
        ob.row=row;
        ob.col=col;
        indexList.push(ob);

        while(indexList.size()>0) {
            Index curIndex=indexList.top();
            indexList.pop();

            Index newIndex;
            newIndex.row=curIndex.row+1;
            newIndex.col=curIndex.col;
            if(isValidIndex(grid,newIndex) && grid[newIndex.row][newIndex.col]=='1'){
                indexList.push(newIndex);
                grid[newIndex.row][newIndex.col]='2';
            }

            newIndex.row=curIndex.row;
            newIndex.col=curIndex.col+1;
            if(isValidIndex(grid,newIndex) && grid[newIndex.row][newIndex.col]=='1'){
                indexList.push(newIndex);
                grid[newIndex.row][newIndex.col]='2';
            }

            newIndex.row=curIndex.row-1;
            newIndex.col=curIndex.col;
            if(isValidIndex(grid,newIndex) && grid[newIndex.row][newIndex.col]=='1'){
                indexList.push(newIndex);
                grid[newIndex.row][newIndex.col]='2';
            }

            newIndex.row=curIndex.row;
            newIndex.col=curIndex.col-1;
            if(isValidIndex(grid,newIndex)&& grid[newIndex.row][newIndex.col]=='1'){
                indexList.push(newIndex);
                grid[newIndex.row][newIndex.col]='2';
            }

        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int totrow=grid.size();
        int totcol=grid[0].size();
        int curIsland=0;

        for(int i=0;i<totrow;i++) {
            for(int j=0;j<totcol;j++) {
                if(grid[i][j]=='1') {
                    curIsland++;
                    bfs(grid,i,j);
                }
            }
        }

        int maxVal=0;
        return curIsland;
    }
};
