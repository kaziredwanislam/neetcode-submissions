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
    int curPos=0;
    int kthVal;
public:
    void inOrderTraversal(TreeNode* node,int k) {
        if(node==NULL)return;
        if(node->left!=NULL)inOrderTraversal(node->left,k);
        curPos++;
        if(curPos==k){
            kthVal=node->val;
            return;
        }
        if(node->right!=NULL)inOrderTraversal(node->right,k);
    }

    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL)return -1;
        inOrderTraversal(root,k);
        return kthVal;
    }
};
