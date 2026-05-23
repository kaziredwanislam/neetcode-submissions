class Index{
    public:
        int x;
        int y;
};

class Solution {
public:
    bool isValid(vector<vector<char>>&board,Index index)
    {
        if(index.x<0 || index.y<0)return false;
        if(index.x>=board.size() || index.y>=board[0].size())return false;
        return true;
    }


    bool isSorrounded(vector<vector<char>>&board,Index index)
    {
        vector<Index>visited;
        vector<vector<int>>marked;
        for(int i=0;i<board.size();i++)
        {
            vector<int>v;
            for(int j=0;j<board[0].size();j++)
            {
                v.push_back(0);
            }
            marked.push_back(v);
        }
        stack<Index>cstack;
        cstack.push(index);
        //cout<<index.x<<" "<<index.y<<endl;
        marked[index.x][index.y]=1;
        while(!cstack.empty())
        {
            Index curIndex=cstack.top();
            cstack.pop();
            //cout<<curIndex.x<<" "<<curIndex.y<<endl;
            visited.push_back(curIndex);

            Index newIndex1;
            newIndex1.x=curIndex.x;
            newIndex1.y=curIndex.y+1;
            /*if(curIndex.x==3 && curIndex.y==3){
                cout<<newIndex1.x<<" "<<newIndex1.y<<" "<<isValid(board,newIndex1)<<endl;
            }*/

            if(!isValid(board,newIndex1))return false;
            if(isValid(board,newIndex1) && marked[newIndex1.x][newIndex1.y]==0 &&board[newIndex1.x][newIndex1.y]=='O')
            {
                marked[newIndex1.x][newIndex1.y]=1;
                cstack.push(newIndex1);
            }



            Index newIndex2;
            newIndex2.x=curIndex.x;
            newIndex2.y=curIndex.y-1;
            /*if(curIndex.x==3 && curIndex.y==3){
                cout<<newIndex2.x<<" "<<newIndex2.y<<" "<<isValid(board,newIndex2)<<endl;
            }*/
            if(!isValid(board,newIndex2))return false;
            if(isValid(board,newIndex2) && marked[newIndex2.x][newIndex2.y]==0 &&board[newIndex2.x][newIndex2.y]=='O')
            {
                marked[newIndex2.x][newIndex2.y]=1;
                cstack.push(newIndex2);
            }

            Index newIndex3;
            newIndex3.x=curIndex.x+1;
            newIndex3.y=curIndex.y;
            /*if(curIndex.x==3 && curIndex.y==3){
                cout<<newIndex3.x<<" "<<newIndex3.y<<" "<<isValid(board,newIndex3)<<endl;
            }*/
            if(!isValid(board,newIndex3))return false;
            if(isValid(board,newIndex3) && marked[newIndex3.x][newIndex3.y]==0 && board[newIndex3.x][newIndex3.y]=='O')
            {
                marked[newIndex3.x][newIndex3.y]=1;
                cstack.push(newIndex3);
            }

            Index newIndex4;
            newIndex4.x=curIndex.x-1;
            newIndex4.y=curIndex.y;
            /*if(curIndex.x==3 && curIndex.y==3){
                cout<<newIndex4.x<<" "<<newIndex4.y<<" "<<isValid(board,newIndex4)<<endl;
            }*/
            if(!isValid(board,newIndex4))return false;
            if(isValid(board,newIndex4) && marked[newIndex4.x][newIndex4.y]==0 && board[newIndex4.x][newIndex4.y]=='O')
            {
                marked[newIndex4.x][newIndex4.y]=1;
                cstack.push(newIndex4);
            }
        }
        /*for(Index index:visited)
        {
            board[index.x][index.y]='X';
        }*/
        return true;
    }

    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                //cout<<i<<" "<<j<<endl;
                if(board[i][j]=='O')
                {
                    Index curIn;
                    curIn.x=i;
                    curIn.y=j;
                    //cout<<i<<" i,j "<<j<<endl;
                    if(isSorrounded(board,curIn))
                    {
                        board[curIn.x][curIn.y]='X';
                    }
                }
            }
        }
    }
};

