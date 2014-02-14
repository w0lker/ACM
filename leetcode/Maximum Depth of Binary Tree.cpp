//递归
//规定一个节点的树深度为1
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
    int maxDepth(TreeNode *root) {
		if(root==NULL) return 0;
		if(root->left==NULL && root->right==NULL) return 1;
		int a = 0,b = 0;
		if(root->left) a = maxDepth(root->left);
		if(root->right) b = maxDepth(root->right);
		return 1+max(a,b);
    }
};