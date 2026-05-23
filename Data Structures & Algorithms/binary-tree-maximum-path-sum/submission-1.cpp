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
    int maxsum=-2000;
public:
    int findsum(TreeNode* node) {
        int leftsum=0;
        int rightsum=0;
        if(node->left!=NULL) {
            leftsum=max(0,findsum(node->left));
        }
        if(node->right!=NULL) {
            rightsum=max(0,findsum(node->right));
        }

        int cursum=max(node->val,node->val+max(leftsum,rightsum));
        if(cursum>maxsum)maxsum=cursum;
        if(node->val+leftsum+rightsum>maxsum)maxsum=node->val+leftsum+rightsum;
        return cursum;
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL)return 0;
        findsum(root);
        return maxsum;
    }
};
