class Solution:
    def solve(self, board: List[List[str]]) -> None:
        s_nodes=[]

        def isValidIndex(r,c):
            tot_row=len(board)
            tot_col=len(board[0])
            if r<0 or r>=tot_row:
                return False
            if c<0 or c>=tot_col:
                return False
            return True
        
        def bfs(r,c):
            issorrounded=True
            v_nodes=[]
            nodes=[]
            nodes.append((r,c))
            v_nodes.append((r,c))
            while len(nodes)>0:
                row,col=nodes.pop()
                if not isValidIndex(row+1,col):
                    issorrounded=False
                elif board[row+1][col]=='O' and (row+1,col) not in v_nodes:
                    nodes.append((row+1,col))
                    v_nodes.append((row+1,col))

                if not isValidIndex(row-1,col):
                    issorrounded=False
                elif board[row-1][col]=='O' and (row-1,col) not in v_nodes:
                    nodes.append((row-1,col))
                    v_nodes.append((row-1,col))

                if not isValidIndex(row,col+1):
                    issorrounded=False
                elif board[row][col+1]=='O' and (row,col+1) not in v_nodes:
                    nodes.append((row,col+1))
                    v_nodes.append((row,col+1))

                if not isValidIndex(row,col-1):
                    issorrounded=False
                elif board[row][col-1]=='O' and (row,col-1) not in v_nodes:
                    nodes.append((row,col-1))
                    v_nodes.append((row,col-1))
            
            if issorrounded:
                for node in v_nodes:
                    row,col=node
                    board[row][col]='X'
            

        for r in range(len(board)):
            for c in range(len(board[0])):
                if board[r][c]=='O':
                    bfs(r,c)


