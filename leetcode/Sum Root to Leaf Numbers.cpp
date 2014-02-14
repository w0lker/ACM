/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int ans;
    void dfs(TreeNode *node,int pre){
        pre = pre*10 + node->val;
        if(node->left==NULL && node->right==NULL){
            ans += pre;
        }else{
            if(node->left) dfs(node->left,pre);
            if(node->right) dfs(node->right,pre);
        }
    }
public:
    int sumNumbers(TreeNode *root) {
        if(root==NULL) return 0;
        ans = 0;
        dfs(root,0);
        return ans;
    }
};