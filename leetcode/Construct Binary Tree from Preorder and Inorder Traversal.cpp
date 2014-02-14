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
	TreeNode* buildTreeHelper(vector<int> &preorder,int low1,int up1,vector<int> &inorder,int low2,int up2);
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.empty()) return NULL;
		buildTreeHelper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};

TreeNode * Solution::buildTreeHelper(vector<int> &preorder,int low1,int up1,vector<int> &inorder,int low2,int up2){
	TreeNode *root = new TreeNode(preorder.at(low1));
	if(preorder.size()==1) return root;
	int pos = low2;
	while(inorder[pos]!=root->val) ++pos;
	if(pos>low2) root->left = buildTreeHelper(preorder,low1+1,low1+pos-low2+1,inorder,low2,pos-1);
	if(pos<up2) root->right = buildTreeHelper(preorder,low1+pos-low2+1,up1,inorder,pos+1,up2);
	return root;
}