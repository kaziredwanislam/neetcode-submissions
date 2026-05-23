class Solution {
public:
    bool isValidMove(vector<vector<int>>matrix,int curRow,int curCol,char move){
        int totRow=matrix.size();
        int totCol=matrix[0].size();

        if(move=='r')curCol++;
        else if(move=='l')curCol--;
        else if(move=='u')curRow--;
        else if(move=='d')curRow++;

        
        if(curRow<0 || curRow>=totRow)return false;
        if(curCol<0 || curCol>=totCol)return false;
        if(matrix[curRow][curCol]==-1000)return false;
        return true;
    }

    char findNextMove(char move) {
        if(move=='r')return 'd';
        else if(move=='d')return 'l';
        else if(move=='l')return 'u';
        else return 'r';
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        char move='r';
        int row=matrix.size();
        int col=matrix[0].size();
        int totIndex=row*col;
        vector<int>spOrder;

        int curRow=0;
        int curCol=0;
        for(int i=0;i<totIndex;i++) {
            //cout<<curRow<<" "<<curCol<<" "<<matrix[curRow][curCol]<<endl;
            spOrder.push_back(matrix[curRow][curCol]);
            matrix[curRow][curCol]=-1000;
            if(!isValidMove(matrix,curRow,curCol,move)) {
                move=findNextMove(move);
            }

            if(move=='r')curCol++;
            else if(move=='l')curCol--;
            else if(move=='u')curRow--;
            else if(move=='d')curRow++;
        }

        return spOrder;
    }
};
