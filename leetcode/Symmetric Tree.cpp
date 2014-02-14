//解法1： 递归式
#define NULL 0

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	bool isSymmetric(TreeNode *ta,TreeNode *tb){
		if(ta==NULL && tb==NULL) return true;
		if( (ta==NULL && tb!=NULL) || (ta!=NULL && tb==NULL)) return false;
		if(ta->val!=tb->val) return false;
		else{
			return(isSymmetric(ta->left,tb->right) && isSymmetric(ta->right,tb->left));
		}
	}
public:
    bool isSymmetric(TreeNode *root) {
        if(root==NULL) return true;
		return isSymmetric(root->left,root->right);
    }
};
//解法2： 迭代式
#include <queue>
using namespace std;
//#define NULL 0

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
		if(root==NULL || (root->left==NULL && root->right==NULL) ) return true;
		if((root->left==NULL && root->right!=NULL) || (root->left!=NULL && root->right==NULL)) return false;
		queue<TreeNode*> q1;
		queue<TreeNode*> q2;
		q1.push(root->left);q2.push(root->right);
		while(!q1.empty()){
			TreeNode *a = q1.front(); q1.pop();
			TreeNode *b = q2.front(); q2.pop();
			if(a->val!=b->val) return false;
			if((a->left==NULL && b->right!=NULL) || (a->left!=NULL && b->right==NULL)
				|| (a->right==NULL && b->left!=NULL) || (a->right!=NULL && b->left==NULL)) return false;
			if(a->left!=NULL){
				q1.push(a->left);
				q2.push(b->right);
			}
			if(a->right!=NULL){
				q1.push(a->right);
				q2.push(b->left);
			}
		}
		return true;
    }
};