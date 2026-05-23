/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class HashMap{
    public:
        vector<vector<Node*>>v;
        HashMap()
        {
            for(int i=0;i<10;i++)
            {
                vector<Node*>vv;
                v.push_back(vv);
            }
        }

        void put(Node* node)
        {
            int index=node->val%10;
            v[index].push_back(node);
        }

        void put(int val)
        {
            Node* node=new Node(val);
            int index=node->val%10;
            v[index].push_back(node);
        }

        bool hasNode(int val)
        {
            int probIndex=val%10;
            for(int i=0;i<v[probIndex].size();i++)
            {
                if(v[probIndex][i]->val==val)return true;
            }
            return false;
        }

        Node* get(int val){
            Node *dummyNode=new Node(-1);
            if(hasNode(val))
            {
                int probIndex=val%10;
                for(int i=0;i<v[probIndex].size();i++)
                {
                    if(v[probIndex][i]->val==val)return v[probIndex][i];
                }
            }
            return dummyNode;
        }
};

class Solution {
public:
    void dfs(HashMap &myMap,Node* curNode,Node* newNode)
    {

            //Node *newNode=new Node(curNode->val);
            //cout<<newNode->val<<endl;
            //myMap.put(newNode);
            for(int i=0;i<curNode->neighbors.size();i++)
            {
                //cout<<"yes"<<endl;
                if(!myMap.hasNode(curNode->neighbors[i]->val))
                {
                    Node *adjNode=new Node(curNode->neighbors[i]->val);
                    myMap.put(adjNode);
                    //cout<<adjNode->val<<"***"<<endl;
                    dfs(myMap,curNode->neighbors[i],adjNode);
                }
            }
            
            for(int i=0;i<curNode->neighbors.size();i++)
            {
                Node *adNode=myMap.get(curNode->neighbors[i]->val);
                newNode->neighbors.push_back(adNode);
            }
        
    }

    Node* cloneGraph(Node* node) {
        if(node==NULL)return NULL;
        Node* newNode=new Node(node->val);
        HashMap myMap;
        myMap.put(newNode);
        dfs(myMap,node,newNode);
        /*for(int i=0;i<node->neighbors.size();i++)
        {
            Node *adNode=myMap.get(node->neighbors[i]->val);
            newNode->neighbors.push_back(adNode);
        }*/
        return newNode;
    }
};
