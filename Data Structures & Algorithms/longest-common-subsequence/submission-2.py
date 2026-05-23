class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        rows=len(text1)+1
        cols=len(text2)+1
        values=0

        grid=[[values for _ in range(cols)] for _ in range(rows)]

        for i in range(1,rows):
            for j in range(1,cols):
                if(text1[i-1]==text2[j-1]):
                    grid[i][j]=grid[i-1][j-1]+1
                else :
                    grid[i][j]=max(grid[i][j-1],grid[i-1][j])
        

        return grid[rows-1][cols-1]
