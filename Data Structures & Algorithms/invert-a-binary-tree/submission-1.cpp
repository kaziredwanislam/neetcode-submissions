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
    void traverse(TreeNode* curNode) {
        if(curNode->left!=nullptr) {
            traverse(curNode->left);
        }
        if(curNode->right!=nullptr) {
            traverse(curNode->right);
        }

        TreeNode* temp=curNode->left;
        curNode->left=curNode->right;
        curNode->right=temp;
    }

    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr)return root;
        traverse(root);
        return root;
    }
};
