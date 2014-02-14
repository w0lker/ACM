//用一个stack先pop父节点，然后push右节点，再push左节点
//注意root为NULL的情况
#include<vector>
#include<stack>
using namespace std;

 struct TreeNode {
	 int val;
	 TreeNode *left;
	 TreeNode *right;
	 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> vec;
        if(root==NULL) return vec;
		stack<TreeNode *> st;
		TreeNode *curr = root;
		st.push(curr);
		while(!st.empty()){
			curr = st.top();
			vec.push_back(curr->val);
			st.pop();
			if(curr->right) st.push(curr->right);
			if(curr->left) st.push(curr->left);
		}
		return vec;
    }
};