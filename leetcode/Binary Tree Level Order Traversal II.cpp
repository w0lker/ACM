//无耻的方法，把levelOrder题目1中的结果放到stack，然后一个一个pop到vector里面……
//或者更简单的，reverse(ans.begin(),ans.end());
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define NULL 0

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector< vector<int> > res;
		stack < vector<int> >ans;
		if(root==NULL) return res;
		queue<TreeNode *> q;
		q.push(root);
		vector<int> vec;
		int cnt1 = 1;
		int cnt2 = 0;
		while(!q.empty()){
			TreeNode *node = q.front();
			q.pop();
			--cnt1;
			if(node->left!=NULL){
				q.push(node->left);
				cnt2 += 1;
			}
			if(node->right != NULL){
				q.push(node->right);
				cnt2 += 1;
			}
			vec.push_back(node->val);
			if(cnt1==0){
				ans.push(vec);
				vec.clear();
				swap(cnt1,cnt2);
			}
		}
		while(!ans.empty()){
			res.push_back(ans.top());
			ans.pop();
		}
		return res;
    }
};