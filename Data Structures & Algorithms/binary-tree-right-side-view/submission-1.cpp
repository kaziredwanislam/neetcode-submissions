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
    vector<TreeNode*> levelOrderTraversal(vector<TreeNode*>level) {
        vector<TreeNode*>newLevel;
        for(int i=0;i<level.size();i++) {
            TreeNode* curNode=level[i];
            if(curNode->left!=nullptr) newLevel.push_back(curNode->left);
            if(curNode->right!=nullptr) newLevel.push_back(curNode->right);
        }
        return newLevel;
    }

    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr)return vector<int>{};
        vector<vector<TreeNode*>> loTraversal;
        vector<TreeNode*>level;
        level.push_back(root);
        loTraversal.push_back(level);
        while(level.size()!=0) {
            vector<TreeNode*>nlevel=levelOrderTraversal(level);
            if(nlevel.size()>0)loTraversal.push_back(nlevel);
            level=nlevel;
        }

        vector<int>rightsides;
        /*for(int i=0;i<loTraversal.size();i++) {
            vector<TreeNode*>curLevel=loTraversal[i];
            for(int j=0;j<curLevel.size();j++) {
                cout<<curLevel[j]->val<<" ";
            }
            cout<<endl;
        }*/

        for(int i=0;i<loTraversal.size();i++) {
            vector<TreeNode*>curLevel=loTraversal[i];
            rightsides.push_back(curLevel[curLevel.size()-1]->val);
        }
        return rightsides;
    }
};
