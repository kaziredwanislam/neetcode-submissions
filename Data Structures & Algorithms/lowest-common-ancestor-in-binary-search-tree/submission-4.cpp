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
    bool pVisit=false;
    bool qVisit=false;
public:
    void inOrderTraversal(TreeNode* node,TreeNode* p,TreeNode* q) {
        
        if(node->left!=NULL)inOrderTraversal(node->left,p,q);
        if(node==p)pVisit=true;
        if(node==q)qVisit=true;
        if(node->right!=NULL)inOrderTraversal(node->right,p,q);
    }

    void findLca (TreeNode* node,TreeNode* p,TreeNode* q,TreeNode*& Lca) {
       pVisit=false;
       qVisit=false;
       if(node->left!=NULL)inOrderTraversal(node->left,p,q);
        bool isInLeftTree=pVisit && qVisit;
        

        pVisit=false;
        qVisit=false;
        if(node->right!=NULL)inOrderTraversal(node->right,p,q);
        bool isInRightTree=pVisit && qVisit;
        
        if(isInLeftTree)findLca(node->left,p,q,Lca);
        else if(isInRightTree)findLca(node->right,p,q,Lca);
        else {
            Lca=node;
            return;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //cout<<" Here"<<endl;
        if(p==NULL && q==NULL)return NULL;
        if(p==NULL)return q;
        if(q==NULL)return p;
        TreeNode* lca=NULL;
        findLca(root,p,q,lca);
        return lca;
    }
};
