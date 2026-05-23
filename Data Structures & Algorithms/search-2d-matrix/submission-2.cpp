class Solution {
public:
    int getTargetRowIndex(vector<vector<int>>& matrix,int target)
    {
        int firstIndex=0;
        int lastIndex=matrix.size()-1;
        
        while(firstIndex<=lastIndex)
        {
            int midIndex=firstIndex+(lastIndex-firstIndex)/2;
            //cout<<"midIndex "<<midIndex<<endl;
            if(midIndex==matrix.size()-1)
            {
                return midIndex;
            }
            if(matrix[midIndex][0]<=target &&matrix[midIndex+1][0]>target)
            {
                return midIndex;
            }
            if(matrix[midIndex][0]<target)
            {
                firstIndex=midIndex+1;
            }
            else
            {
                lastIndex=midIndex-1;
            }
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int targetRowIndex;
        if(target>matrix[matrix.size()-1][matrix[0].size()-1])return false;
        if(target<matrix[0][0])return false;
        if(matrix.size()==1)targetRowIndex=0;
        else
        {
            targetRowIndex=getTargetRowIndex(matrix,target);
        }
       // cout<<"tR: "<<targetRowIndex<<endl;
        vector<int>targetRow=matrix[targetRowIndex];
        int firstIndex=0;
        int lastIndex=targetRow.size()-1;
        while(firstIndex<=lastIndex)
        {
            int midIndex=firstIndex+(lastIndex-firstIndex)/2;
            if(targetRow[midIndex]==target)return true;
            if(targetRow[midIndex]<target)firstIndex=midIndex+1;
            if(targetRow[midIndex]>target)lastIndex=midIndex-1;
        }
        return false;
    }
};    