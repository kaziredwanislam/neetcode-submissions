class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        def isValidIndex(r,c):
            tot_row=len(grid)
            tot_col=len(grid[0])
            if r<0 or r>=tot_row:
                return False
            if c<0 or c>=tot_col:
                return False
            return True
        
        nodes=[]
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if grid[row][col]==0:
                    nodes.append((row,col))
        
        dis=0
        while len(nodes)>0:
            dis+=1
            new_nodes=[]
            for row,col in nodes:
                if isValidIndex(row+1,col)==True and grid[row+1][col]!=-1 and grid[row+1][col]>dis:
                    grid[row+1][col]=dis
                    new_nodes.append((row+1,col)) 
                if isValidIndex(row-1,col)==True and grid[row-1][col]!=-1 and grid[row-1][col]>dis:
                    grid[row-1][col]=dis
                    new_nodes.append((row-1,col))            
                if isValidIndex(row,col+1)==True and grid[row][col+1]!=-1 and grid[row][col+1]>dis:
                    grid[row][col+1]=dis
                    new_nodes.append((row,col+1)) 
                if isValidIndex(row,col-1)==True and grid[row][col-1]!=-1 and grid[row][col-1]>dis:
                    grid[row][col-1]=dis
                    new_nodes.append((row,col-1)) 
            nodes=new_nodes


                           

