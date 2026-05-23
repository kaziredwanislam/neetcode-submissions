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
    int getDepth(TreeNode* cNode,int &diameter)
    {
        if(cNode==nullptr)return 0;
        int leftDepth=1+getDepth(cNode->left,diameter);
        int rightDepth=1+getDepth(cNode->right,diameter);
        int curDiameter=leftDepth-1+rightDepth-1;
        if(curDiameter>diameter)
        {
            diameter=curDiameter;
            //cout<<cNode->val<<" "<<leftDepth<<" "<<rightDepth<<" "<<diameter<<endl;
           
        }
        return max(leftDepth,rightDepth);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        getDepth(root,diameter);
        return diameter;
    }
};
