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
    void traverse(TreeNode*node,int height,int &maxHeight)
    {
        height=height+1;
        maxHeight=max(maxHeight,height);
        if(node->left!=nullptr){
            traverse(node->left,height,maxHeight);
        }
        if(node->right!=nullptr){
            traverse(node->right,height,maxHeight);
        }
    }

    int maxDepth(TreeNode* root) {
        if(root==nullptr)return 0;
        int maxHeight=0;
        traverse(root,0,maxHeight);
        return maxHeight;
    }
};
