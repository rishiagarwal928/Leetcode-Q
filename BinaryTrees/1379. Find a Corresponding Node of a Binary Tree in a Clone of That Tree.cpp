/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void dfs(TreeNode* original, TreeNode* cloned, TreeNode* target,TreeNode* &res){
        if(!original) return;
        if(target == original){
            res = cloned;
        }
            dfs(original->left,cloned->left,target,res);
            dfs(original->right,cloned->right,target,res);
        return;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* res = nullptr;
        dfs(original,cloned,target,res);
        return res;
    }
};
