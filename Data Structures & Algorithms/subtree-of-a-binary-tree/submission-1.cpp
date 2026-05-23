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
    bool subTree=false;
public:
    void isSameTree(TreeNode* pNode,TreeNode* qNode ) {
        if(pNode->val!=qNode->val)sameTree=false;
        if(pNode->left==nullptr && qNode->left!=nullptr) sameTree=false;
        if(qNode->left==nullptr && pNode->left!=nullptr) sameTree=false;
        if(pNode->right==nullptr && qNode->right!=nullptr)sameTree=false;
        if(qNode->right==nullptr && pNode->right!=nullptr)sameTree=false;

        if(sameTree) {
            if(pNode->left!=nullptr) {
                isSameTree(pNode->left,qNode->left);
            }
            if(pNode->right!=nullptr) {
                isSameTree(pNode->right,qNode->right);
            }
        }
    }

    void checkSubTree(TreeNode* root,TreeNode* subRoot) {
        sameTree=true;
        isSameTree(root,subRoot);
        if(sameTree)subTree=true;

        if(!subTree) {
            if(root->left!=nullptr)checkSubTree(root->left,subRoot);
            if(root->right!=nullptr)checkSubTree(root->right,subRoot);
        }
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr && subRoot==nullptr)return true;
        if(root==nullptr)return false;
        if(subRoot==nullptr) return false;
        checkSubTree(root,subRoot);
        return subTree;
    }
};
