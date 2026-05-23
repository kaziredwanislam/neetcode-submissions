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
    void inOrderSearch(TreeNode* node,vector<int>&nodeval) {
        if(node->left)inOrderSearch(node->left,nodeval);
        nodeval.push_back(node->val);
        if(node->right)inOrderSearch(node->right,nodeval);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int>nodeval;
        inOrderSearch(root,nodeval);

        int index=k-1;
        int val;
        for(int i=0;i<nodeval.size();i++) {
            if(i==index) {
                val=nodeval[i];
                break;
            }
        }
        return val;
    }
};
