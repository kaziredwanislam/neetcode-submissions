class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        tot_component=0
        visited=[False for _ in range(n)] 
        graph=[[] for _ in range(n)]
        for edge in edges:
            fNode=edge[0]
            lNode=edge[1]
            graph[fNode].append(lNode)
            graph[lNode].append(fNode)

        def bfs(node):
            nonlocal tot_component
            node_q=[]
            node_q.append(node)
            tot_component+=1
            while len(node_q)>0:
                cNode=node_q.pop()
                #visited[node]=True
                for node in graph[cNode]:
                    if visited[node]==False:
                        visited[node]=True
                        node_q.append(node)
        
        for i in range(n):
            if visited[i]==False:
                visited[i]=True
                bfs(i)
        
        return tot_component

        