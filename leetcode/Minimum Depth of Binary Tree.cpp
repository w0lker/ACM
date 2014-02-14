//注意某一子树为空的情况不能直接用depth = 1 + min(depth_left + depth_right)

#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode *root) {
		if(root==NULL) return 0;
		if(root->left==NULL && root->right==NULL) return 1;
		int a = 0,b = 0;
		if(root->left!=NULL){
			a = minDepth(root->left);
			if(root->right==NULL) return a + 1;
		}
		if(root->right!=NULL){
			b = minDepth(root->right);
			if(root->left==NULL) return b + 1;
		}
		return 1+min(a,b);
    }
};