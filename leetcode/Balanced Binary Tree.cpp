/*
解法1： 递归调用计算每个点的左右子树高度是否相差1以内。
*/
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	int depth(TreeNode *node){
		if(node->left==NULL && node->right==NULL) return 0;
		else{
			int d = 0;
			if(node->left!=NULL) d = depth(node->left);
			if(node->right!=NULL) d = max(d,depth(node->right));
			return d+1;
		}
	}
public:
    bool isBalanced(TreeNode *root) {
		if(root==NULL) return true;
		//dl dr ，左右子树的depth千万不能初始化为0，因为那样等于是有一个节点了。
		//eg: {1,#,2,#,3}
        int dl = -1,dr = -1;
		if(root->left!=NULL) dl = depth(root->left);
		if(root->right!=NULL) dr = depth(root->right);
		if(abs(dl-dr)>1) return false;
		else{
			bool bl = true,br = true;
			if(root->left!=NULL) bl = isBalanced(root->left);
			if(root->right!=NULL) br = isBalanced(root->right);
			return bl && br;
		}
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
解法2：在计算depth的过程中若发现左右子树高度相差超过1则直接停止。
*/
#include <algorithm>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	int depth(TreeNode *node,bool &unBalanced){
		if(unBalanced) return -1;
		if(node->left==NULL & node->right==NULL) return 0;
		int dl = -1,dr = -1;
		if(node->left!=NULL) dl = depth(node->left,unBalanced);
		if(node->right!=NULL) dr = depth(node->right,unBalanced);
		if(abs(dl-dr)>1){
			unBalanced = true;
			return -1;
		}
		return 1 + max(dl,dr);
	}
public:
    bool isBalanced(TreeNode *root) {
		if(root==NULL) return true;
        bool unBalanced = false;
		depth(root,unBalanced);
		return unBalanced?false:true;
    }
};

//数据
//TreeNode *root = new TreeNode(5);	TreeNode *r1 = new TreeNode(3);	TreeNode *r2 = new TreeNode(1);
//		TreeNode *r3= new TreeNode(2);	TreeNode *r4 = new TreeNode(4); TreeNode *r5 = new TreeNode(7);
//		TreeNode *r6= new TreeNode(6);
//	root->left = r1;root->right = r2;
//	r1->left = r3;//r1->right=r4; 
//	r3->left = r5; 
//	//r2->right = r6;