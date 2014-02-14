/**
几个牛逼的解法：
blog.csdn.net/havenoidea/article/details/11822019
blog.unieagle.net/2012/12/16/leetcode-problemflatten-binary-tree-to-linked-list/
blog.csdn.net/ithomer/article/details/8873097
**/

#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	TreeNode *flatten_helper(TreeNode *root) {
        if(root->left==NULL && root->right==NULL) return root; 
		TreeNode *bottom;
		TreeNode *l_root=root->left,*l_bottom=NULL,*r_root=root->right,*r_bottom=root->right;
		if(l_root!=NULL) l_bottom = flatten_helper(l_root);
		if(r_root!=NULL) r_bottom = flatten_helper(r_root);
		if(l_root!=NULL){
			root->right = l_root;
			root->left = NULL;
			bottom = l_bottom;
			if(r_root!=NULL){
				l_bottom->right = r_root;
				bottom = r_bottom;
			}
		}else bottom = r_bottom;
		return bottom;
    }
public:
    void flatten(TreeNode *root) {
        if(root==NULL) return;
		flatten_helper(root);
    }
};