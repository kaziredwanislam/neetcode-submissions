class Solution {
public:
    int findParent(vector<int>&parents,int cNode) {
        int parent=parents[cNode];
        while(parents[cNode]!=cNode) {
            parent=parents[cNode];
            cNode=parent;
        }

        return parent;
    }

    void merge(vector<int>&parents,int n1,int n2) {
        int n1parent=findParent(parents,n1);
        int n2parent=findParent(parents,n2);
        parents[n1parent]=n2parent;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int totNodes=edges.size();
        vector<int>parents(totNodes,-1);
        for(int i=0;i<totNodes;i++) {
            parents[i]=i;
        }

        vector<int>visited(totNodes,0);
        vector<int>rededge;
        for(int i=0;i<edges.size();i++) {
            int fNode=edges[i][0];
            int lNode=edges[i][1];
            if(visited[fNode]==0 && visited[lNode]==0) {
                visited[fNode]=1;
                visited[lNode]=1;
                merge(parents,fNode,lNode);
            }

            else if(visited[fNode]==0) {
                visited[fNode]=1;
                merge(parents,fNode,lNode);
            }

            else if(visited[lNode]==0) {
                visited[lNode]=1;
                merge(parents,lNode,fNode);
            }

            else {
                if(findParent(parents,fNode)==findParent(parents,lNode)) {
                    rededge.clear();
                    rededge.push_back(fNode);
                    rededge.push_back(lNode);
                }
                else {
                    merge(parents,fNode,lNode);
                }
            }

        }
        return rededge;
    }
};
