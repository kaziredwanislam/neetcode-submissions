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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<TreeNode*>loOrder;
        vector<vector<int>>ans;
        if(root==nullptr)return ans;
        ans.push_back({root->val});
        loOrder.push_back(root);
        while(loOrder.size()>0) {
            vector<TreeNode*>curOrder=loOrder;
            loOrder.clear();
            vector<int>v;
            for(int i=0;i<curOrder.size();i++) {
                TreeNode* curNode=curOrder[i];
                if(curNode->left){
                    loOrder.push_back(curNode->left);
                    v.push_back(curNode->left->val);
                }
                if(curNode->right) {
                    loOrder.push_back(curNode->right);
                    v.push_back(curNode->right->val);
                }
            }
            if(v.size()>0)ans.push_back(v);
        }

        return ans;
    }
};
