/**
必须要加入额外信息，一种方法是把treenode聚合成新的node，在里面添加visied信息。
另一种方法是
用一个flag数组记住是否为第二次访问某节点，如果是第二次访问则直接pop掉，如果是第一次访问看他右子节点是否为空，
若为空也直接pop，不为空则把右子节点push进来，然后push掉后续的所有左子节点。
也可以用两个stack来实现
**/

#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> vec;
		if(root==NULL) return vec;
		stack<TreeNode*> st;
		TreeNode *lastVisit = NULL;
		int flag[500];
		memset(flag,0,sizeof(flag));
		TreeNode *curr = root;
		while(curr){
			st.push(curr);
			curr = curr->left;
		}
		while(!st.empty()){
			curr = st.top();
			if(curr->right && flag[st.size()]==0){
				flag[st.size()] = 1;
				curr = curr->right;
				while(curr){
					st.push(curr);
					curr = curr->left;
				}
			}else{
				vec.push_back(curr->val);
				flag[st.size()] = 0;
				st.pop();
			}
		}
		return vec;
    }
};



/**
//另一种方法：用pre来记录之前被访问过的点，那么当访问某节点时，pre刚好是他的左子节点
//说明该节点右子树访问完毕，可以将其pop掉。

#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> vec;
		if(root==NULL) return vec;
		stack<TreeNode*> st;
		TreeNode *lastVisit = NULL;
		TreeNode *pre = NULL;
		TreeNode *curr = root;
		while(curr){
			st.push(curr);
			curr = curr->left;
		}
		while(!st.empty()){
			curr = st.top();
			if(curr->right!=NULL && curr->right!=pre){
				curr = curr->right;
				while(curr){
					st.push(curr);
					curr = curr->left;
				}
			}else{
				vec.push_back(curr->val);
				pre = curr;
				st.pop();
			}
		}
		return vec;
    }
};

**/