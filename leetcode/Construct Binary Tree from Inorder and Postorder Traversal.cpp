#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
	TreeNode *buildTree( vector<int> &postorder,vector<int> &inorder,int low1,int up1,int low2,int up2) {
        TreeNode *root = new TreeNode(postorder.at(up1));
		if(postorder.size()==1) return root;
		int pos = low2;
		while(inorder[pos]!=root->val) ++pos;
		if(pos>low2) root->left = buildTree(postorder,inorder,low1,low1+pos-low2-1,low2,pos-1);
		if(pos<up2) root->right = buildTree(postorder,inorder,low1+pos-low2,up1-1,pos+1,up2);
		return root;
    }
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(postorder.empty()) return NULL;
		return buildTree(postorder,inorder,0,postorder.size()-1,0,inorder.size()-1);
    }
};