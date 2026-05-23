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
    void inOrderTraversal(TreeNode* node,vector<int>&iOList) {
        if(node->left!=nullptr) {
            inOrderTraversal(node->left,iOList);
        }
        iOList.push_back(node->val);

        if(node->right!=nullptr) {
            inOrderTraversal(node->right,iOList);
        }
    }

    bool isValidBST(TreeNode* root) {
        if(root==nullptr)return true;
        vector<int>iOList;
        inOrderTraversal(root,iOList);

        for(int i=0;i<iOList.size();i++) {
            cout<<iOList[i]<<" ";
        }

        for(int i=0;i<iOList.size()-1;i++) {
            if(iOList[i]>=iOList[i+1])return false;
        }    
        return true;
    }
};
