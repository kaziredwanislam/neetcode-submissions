class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        tot_island=0
        tot_row=len(grid)
        tot_col=len(grid[0])

        def is_valid_index(row,col):
            if row>=0 and row<tot_row and col>=0 and col<tot_col:
                return True
            return False
        
        
        def bfs(row,col):
            nonlocal tot_island
            index_q=[]
            index_q.append((row,col))
            tot_island+=1

            while len(index_q)>0:
                r,c=index_q.pop()
                grid[r][c]="2"
                if is_valid_index(r-1,c) and grid[r-1][c]=="1":
                    index_q.append((r-1,c))
                if is_valid_index(r,c-1) and grid[r][c-1]=="1":
                    index_q.append((r,c-1)) 
                if is_valid_index(r+1,c) and grid[r+1][c]=="1":
                    index_q.append((r+1,c))
                if is_valid_index(r,c+1) and grid[r][c+1]=="1":
                    index_q.append((r,c+1))

        for row in range(tot_row):
            for col in range(tot_col):
                if grid[row][col]=="1":
                    bfs(row,col)
        
        return tot_island