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
    int depth=0;
public:
    void traverse(TreeNode* curNode,int d) {
        if(d>depth)depth=d;
        if(curNode->left!=nullptr) traverse(curNode->left,d+1);
        if(curNode->right!=nullptr)traverse(curNode->right,d+1);
    }
    int maxDepth(TreeNode* root) {
        if(root==nullptr)return 0;
        traverse(root,1);
        return depth;
    }
};
