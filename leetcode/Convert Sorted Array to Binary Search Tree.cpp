//这一题我理解起来有点问题{4,2,5,1,3}  按说也是平衡搜索二叉树，但是这种取数组
//中间元素作为根节点的做法确并不适用
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
	TreeNode *help(vector<int> &num,int low,int up){
		int mid = (low+up)/2;
		TreeNode *node = new TreeNode(num[mid]);
		if(low==up) return node;
		if(mid>low) node->left = help(num,low,mid-1);
		if(mid<up) node->right = help(num,mid+1,up);
		return node;
	}
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(num.empty()) return NULL;
		return help(num,0,num.size()-1);
    }
};