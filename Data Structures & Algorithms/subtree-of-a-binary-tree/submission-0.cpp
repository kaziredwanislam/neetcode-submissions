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
    bool isSubVec(vector<int>&v,vector<int>&subV,int index) {
        int startIndex=index;
        int lastIndex=index+subV.size()-1;
        if(lastIndex>=v.size())return false;
        int j=0;
        for(int i=startIndex;i<=lastIndex;i++) {
            if(v[i]!=subV[j++])return false;
        }
        return true;
    }

    void inOrderTraversal(TreeNode* p,vector<int>& inOrderList) {
        if(p->left!=NULL)inOrderTraversal(p->left,inOrderList);
        if(p->left==NULL)inOrderList.push_back(-200);
        inOrderList.push_back(p->val);
        if(p->right!=NULL)inOrderTraversal(p->right,inOrderList);
        if(p->right==NULL)inOrderList.push_back(200);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==NULL)return true;
        if(subRoot==NULL)return false;
        vector<int>inOrderList1;
        vector<int>inOrderList2;
        
        inOrderTraversal(root,inOrderList1);
        inOrderTraversal(subRoot,inOrderList2);

        for(int i=0;i<inOrderList1.size();i++) {
            if(inOrderList1[i]==inOrderList2[0]) {
                if(isSubVec(inOrderList1,inOrderList2,i))return true;
            }
        }
        return false;
    }
};
