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
    void inOrderTraversal(TreeNode* node,vector<int>&ioList) {
        if(node->left!=NULL)inOrderTraversal(node->left,ioList);
        ioList.push_back(node->val);
        if(node->right!=NULL)inOrderTraversal(node->right,ioList);
    }

    bool isValidBST(TreeNode* root) {
        if(root==NULL)return true;
        vector<int>ioList;
        inOrderTraversal(root,ioList);
        int cElem=ioList[0];
        for(int i=1;i<ioList.size();i++) {
            if(cElem>=ioList[i])return false;
            cElem=ioList[i];
        }
        return true;
    }
};
