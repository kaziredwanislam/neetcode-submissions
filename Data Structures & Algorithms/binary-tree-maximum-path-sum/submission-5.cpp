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
int max(int a,int b,int c) {
    if(a>=b && a>=c)return a;
    if(b>=a && b>=c)return b;
    return c;
}

int max(int a,int b) {
    if(a>=b)return a;
    return b;
}

    int postOrderTraverse(TreeNode* node,int & pathSum) {
        int leftPathSum=0;
        int rightPathSum=0;
        if(node->left) {
            leftPathSum=postOrderTraverse(node->left,pathSum);
        }
        if(node->right) {
            rightPathSum=postOrderTraverse(node->right,pathSum);
        }

        pathSum= max(pathSum,max(max(leftPathSum+rightPathSum+node->val,leftPathSum+node->val),max(rightPathSum+node->val,node->val)));
        //if(leftPathSum== && rightPathSum==-100000)return node->val;
        //if(leftPathSum==-100000)return max(rightPathSum+node->val,node->val);
        //if(rightPathSum==-100000)return max(leftPathSum+node->val,node->val);
        return max(node->val,leftPathSum+node->val,rightPathSum+node->val);
    }

    int maxPathSum(TreeNode* root) {
        int pathSum=-100000;
        postOrderTraverse(root,pathSum);
        return pathSum;
    }
};
