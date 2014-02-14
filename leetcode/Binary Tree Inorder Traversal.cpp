#include <stack>
#include <vector>
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
    vector<int> inorderTraversal(TreeNode *root) {
		vector<int> vec;
        if(root==NULL) return vec;
		stack<TreeNode*> st;
		st.push(root);
		TreeNode* curr = root->left;
		while(curr!=NULL) {
			st.push(curr);
			curr = curr->left;
		}
		while(!st.empty()){
			TreeNode *curr = st.top();
			st.pop();
			vec.push_back(curr->val);
			if(curr->right!=NULL){
				curr = curr->right;
				while(curr!=NULL){
					st.push(curr);
					curr = curr->left;
				}
			}
		}
		return vec;
    }
};