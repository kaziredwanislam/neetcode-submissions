/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:
    vector<string>splitstringbycomma(string& input) {
        vector<string>result;
        stringstream ss(input);
        string token;
        while(getline(ss,token,',')) {
            result.push_back(token);
        }
        return result;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        queue<TreeNode*>cList;
        if(root==NULL){
            s="N";
            return s;
        }
        cList.push(root);
        

            while(!cList.empty()) {
                TreeNode* cNode=cList.front();
                cList.pop();
                if(cNode!=NULL){
                    s+=to_string(cNode->val)+",";
                    cList.push(cNode->left);
                    cList.push(cNode->right);
                }
                else{ s+="N,";}
                
            }
        if(!s.empty()) {
            s.pop_back();
        }
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string>nodestr=splitstringbycomma(data);
        vector<TreeNode*>nodes;
        for(int i=0;i<nodestr.size();i++) {
            if(nodestr[i]!="N")
            {
                TreeNode* cNode=new TreeNode(stoi(nodestr[i]));
                nodes.push_back(cNode);
            }
            else nodes.push_back(NULL);
        }

        int totalInnerNodes=floor(nodes.size()/2);
        int curNode=0;
        for(int i=0;i<nodes.size();i++)
        {
            TreeNode* cNode=nodes[i];
            if(cNode!=NULL && 2*curNode+2<nodes.size())
            {
                TreeNode* lNode=nodes[2*curNode+1];
                TreeNode* rNode=nodes[2*curNode+2];
                cNode->left=lNode;
                cNode->right=rNode;
                //cout<<curNode<<" "<<cNode->val<<endl;
                curNode++;
            }
        }
        return nodes[0];
    }
};
