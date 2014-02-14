/**
自底向上的思路。
注意，题目要求搜索二叉树满足左子树均“小于”根节点，而不是“不大于”根节点
**/
#define NULL 0

struct Range{
	int low,up;
	Range(int l=0,int u=0):low(l),up(u){}
	Range(const Range &other):low(other.low),up(other.up){}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	Range test(TreeNode *node,bool &illegal){
		if(illegal) return Range(0,0);
		int min=node->val,max=node->val;
		if(node->left!=NULL){
			Range r = test(node->left,illegal);
			if(r.up >= node->val){
				illegal = true;
				return Range(0,0);
			}else min = r.low;
		}
		if(node->right!=NULL){
			Range r = test(node->right,illegal);
			if(r.low <= node->val){
				illegal = true;
				return Range(0,0);
			}else max = r.up;
		}
		return Range(min,max);
	}
public:
    bool isValidBST(TreeNode *root) {
		if(root==NULL) return true;
        bool illegal = false;
		test(root,illegal);
		return illegal?false:true;
    }
};

/**
自顶向下的思路，非常简洁。
**/
#define NULL 0
#include <climits>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	bool test(TreeNode *node,int min,int max){
		if(node==NULL) return true;
		if(node->val <= min || node->val >= max) return false;
		return (test(node->left,min,node->val) && test(node->right,node->val,max));
	}
public:
    bool isValidBST(TreeNode *root) {
		return test(root,INT_MIN,INT_MAX);
    }
};