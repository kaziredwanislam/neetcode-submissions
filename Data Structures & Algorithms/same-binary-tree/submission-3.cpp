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
    bool sameTree=true;
public:
    void traverse(TreeNode* pNode,TreeNode* qNode) {
        if(pNode->val!=qNode->val)sameTree=false;
        if(pNode->left==nullptr && qNode->left!=nullptr)sameTree=false;
        if(pNode->right==nullptr && qNode->right!=nullptr)sameTree=false;

        if(sameTree) {
            if(pNode->left !=nullptr && qNode->left!=nullptr)traverse(pNode->left,qNode->left);
            if(pNode->right!=nullptr && qNode->right!=nullptr)traverse(pNode->right,qNode->right);
        }
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr)return true;
        if(p==nullptr)return false;
        if(q==nullptr)return false;

        traverse(p,q);
        return sameTree;
    }
};
