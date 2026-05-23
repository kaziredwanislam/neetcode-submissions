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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>loList;
        queue<TreeNode*>cList;
        if(root==NULL)return loList;    
        cList.push(root);

        while(true) {
            queue<TreeNode*>nList;
            vector<int>v;
            while(!cList.empty()) {
                TreeNode* cNode=cList.front();
                cList.pop();
                
                if(cNode->left!=NULL) {
                    nList.push(cNode->left);
                //v.push_back(cNode->left->val);
                }
                if(cNode->right!=NULL) {
                    nList.push(cNode->right);
                }

                v.push_back(cNode->val);
            }
            loList.push_back(v);
            cList=nList;
            if(nList.empty())break;
        }
        return loList;
    }
};
