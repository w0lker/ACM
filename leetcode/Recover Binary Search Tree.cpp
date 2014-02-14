//ºÃÌâÄ¿£¡

#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
	TreeNode *pre,*pa,*pb;
	void test(TreeNode *root){
		if(root==NULL) return;
		test(root->left);
		if(pre!=NULL) {
			if(pre->val > root->val){
				if(pa==NULL) pa = pre,pb = root;
				else pb = root;
			}
		}
		pre = root;
		test(root->right);
	}
public:
    void recoverTree(TreeNode *root) {
        if(root==NULL) return;
		pre=NULL;
		pa=NULL;
		pb=NULL;
		test(root);
		swap(pa->val,pb->val);
    }
};