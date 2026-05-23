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
    TreeNode* traverse(TreeNode* node)
    {
        if(node->left!=nullptr)traverse(node->left);
        if(node->right!=nullptr)traverse(node->right);

        if(node->left!=nullptr && node->right!=nullptr)
        {
            TreeNode* temp=node->left;
            node->left=node->right;
            node->right=temp;
        }
        else if(node->left!=nullptr)
        {
            node->right=node->left;
            node->left=nullptr;
        }
        else if(node->right!=nullptr)
        {
            node->left=node->right;
            node->right=nullptr;
        }
        return node;
        
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr)return nullptr;
        return traverse(root);
    }
};
