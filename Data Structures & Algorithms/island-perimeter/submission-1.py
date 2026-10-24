class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        connections=[[0 for _ in range(len(grid[0]))]for _ in range(len(grid))]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                connection=0
                if grid[i][j]==1:
                    if i-1>=0 and grid[i-1][j]!=0:
                        connection+=1
                    if i+1<len(grid) and grid[i+1][j]!=0:
                        connection+=1
                    if j+1<len(grid[0]) and grid[i][j+1]!=0:
                        connection+=1
                    if j-1>=0 and grid[i][j-1]!=0:
                        connection+=1
                    connections[i][j]=connection

    
        #print(connections)
        perimeter=0
        for i in range (len(connections)):
            for j in range(len(connections[0])):
                if connections[i][j]==1:
                    perimeter+=3
                elif connections[i][j]==2:
                    perimeter+=2
                elif connections[i][j]==3:
                    perimeter+=1
        if perimeter==0:
            return 4
        return perimeter               
                