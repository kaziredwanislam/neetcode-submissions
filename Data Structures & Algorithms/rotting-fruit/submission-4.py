class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        def isValidIndex(r,c):
            tot_row=len(grid)
            tot_col=len(grid[0])
            if r<0 or r>=tot_row:
                return False
            if c<0 or c>=tot_col:
                return False
            return True
        
        def bfs(nodes):
            #nodes.append((r,c))
            time=-1
            while len(nodes)>0:
                time+=1
                print(nodes)
                cur_nodes=[]
                for row,col in nodes:
                    if isValidIndex(row+1,col) and grid[row+1][col]==1:
                        grid[row+1][col]=2
                        cur_nodes.append((row+1,col))
                    if isValidIndex(row-1,col) and grid[row-1][col]==1:
                        grid[row-1][col]=2
                        cur_nodes.append((row-1,col))
                    if isValidIndex(row,col+1) and grid[row][col+1]==1:
                        grid[row][col+1]=2
                        cur_nodes.append((row,col+1))
                    if isValidIndex(row,col-1) and grid[row][col-1]==1:
                        grid[row][col-1]=2
                        cur_nodes.append((row,col-1))
                nodes=cur_nodes
              
            return time       
        
        
        nodes=[]
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if grid[r][c]==2:
                    nodes.append((r,c))
        
        time=bfs(nodes)
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                print(grid[r][c],end=" ")
            print()

        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if grid[r][c]==1:
                    return -1
        
        return max(time,0)
                
