class Index {
    public:
        int row;
        int col;
};

class Solution {
public:
    void setRowZero(vector<vector<int>>&matrix,int row,int col) {
        for(int i=0;i<matrix[0].size();i++) {
            matrix[row][i]=0;
        }
    }

    void setColZero(vector<vector<int>>&matrix,int row,int col) {
        for(int i=0;i<matrix.size();i++) {
            matrix[i][col]=0;
        }
    }

    void showMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[0].size();j++) {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<Index>zeroes;
        
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(matrix[i][j]==0) {
                    Index ind;
                    ind.row=i;
                    ind.col=j;
                    zeroes.push_back(ind);
                }
            }
        }

        for(int i=0;i<zeroes.size();i++) {
            setRowZero(matrix,zeroes[i].row,zeroes[i].col);
            setColZero(matrix,zeroes[i].row,zeroes[i].col);
        }
    }
};
