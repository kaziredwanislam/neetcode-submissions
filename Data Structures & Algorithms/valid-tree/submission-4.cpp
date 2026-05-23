class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n,vector<int>(n,0));
        for(int i=0;i<edges.size();i++) {
            int fNode=edges[i][0];
            int lNode=edges[i][1];
            graph[fNode][lNode]=1;
            graph[lNode][fNode]=1;
        }

        vector<bool>visited(n,false);
        vector<int>parents(n,-1);   
        stack<int>cNodes;
        cNodes.push(0);
        while(!cNodes.empty()) {
            int cNode=cNodes.top();
            cNodes.pop();
            visited[cNode]=true;

            for(int i=0;i<n;i++) {
                if(graph[cNode][i]==1 && parents[cNode]!=i) {
                    if(visited[i]){
                        cout<<"Visited: "<<i<<" "<<"edge "<<cNode<<" "<<i<<endl;
                        cout<<"Parent of "<<i<<" "<<parents[i]<<endl;
                        return false;
                    }
                    cNodes.push(i);
                    parents[i]=cNode;
                }
            }
        }

        for(int node:visited) {
            if(!node)return false;
        }
        return true;

    }
};