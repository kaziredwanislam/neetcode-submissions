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
    int good_nodes=0;
public:
    void traversal(TreeNode* curNode,int maxVal) {
        if(curNode->val>=maxVal) {
            maxVal=curNode->val;
            good_nodes++;
        }
        if(curNode->left!=nullptr)traversal(curNode->left,maxVal);
        if(curNode->right!=nullptr)traversal(curNode->right,maxVal);
    }

    int goodNodes(TreeNode* root) {
        if(root==nullptr)return 0;
        traversal(root,root->val);
        return good_nodes;    
    }
};
