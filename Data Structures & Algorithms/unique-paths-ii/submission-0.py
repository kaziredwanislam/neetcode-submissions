class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        tot_row=len(obstacleGrid)
        tot_col=len(obstacleGrid[0])
        if obstacleGrid[tot_row-1][tot_col-1]==1:
            return 0
        
        paths=[[0 for _ in range(len(obstacleGrid[0]))]for _ in range(len(obstacleGrid))]
        for i in range(tot_row-1,-1,-1):
            if obstacleGrid[i][tot_col-1]==1:
                break
            paths[i][tot_col-1]=1
        
        for i in range(tot_col-1,-1,-1):
            if obstacleGrid[tot_row-1][i]==1:
                break
            paths[tot_row-1][i]=1
        
        #print(paths)
        #print("Hello")
        for i in range(tot_row-2,-1,-1):
            for j in range(tot_col-2,-1,-1):
                if obstacleGrid[i][j]!=1:
                    paths[i][j]=paths[i+1][j]+paths[i][j+1]
        
        return paths[0][0]