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
    void inOrderTraversal(TreeNode* p,vector<int>& inOrderList) {
        if(p->left!=NULL)inOrderTraversal(p->left,inOrderList);
        if(p->left==NULL)inOrderList.push_back(-200);
        inOrderList.push_back(p->val);
        if(p->right!=NULL)inOrderTraversal(p->right,inOrderList);
        if(p->right==NULL)inOrderList.push_back(200);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)return true;
        if(p==NULL || q==NULL)return false;
        vector<int>inOrderList1;
        vector<int>inOrderList2;
        
        inOrderTraversal(p,inOrderList1);
        inOrderTraversal(q,inOrderList2);
        if(inOrderList1.size()!=inOrderList2.size())return false;
        for(int i=0;i<inOrderList1.size();i++) {
            if(inOrderList1[i]!=inOrderList2[i])return false;
        }
        return true;
    }
};
