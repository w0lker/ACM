//������stack���汣�����level��Ԫ�ؾ�����
//ע���������ʱ��Ҫ�ȶ����ӽڵ�
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector< vector<int> > ans;
		if(root==NULL) return ans;
		vector<int> vec;
		stack<TreeNode *> st1;
		stack<TreeNode *> st2;
		st1.push(root);
		bool flag = true;
		TreeNode *curr;
		while(!st1.empty() || !st2.empty()){
			if(flag){
				curr = st1.top();
				st1.pop();
				vec.push_back(curr->val);
				if(curr->left) st2.push(curr->left);
				if(curr->right) st2.push(curr->right);
				if(st1.empty()){
					flag = !flag;
					ans.push_back(vec);
					vec.clear();
				}
			}else{
				curr = st2.top();
				st2.pop();
				vec.push_back(curr->val);
				if(curr->right) st1.push(curr->right);
				if(curr->left) st1.push(curr->left);
				if(st2.empty()){
					flag = !flag;
					ans.push_back(vec);
					vec.clear();
				}
			}
			
		}
		return ans;
    }
};

//���һ���д����
//������stack���汣�����level��Ԫ�ؾ�����
//ע���������ʱ��Ҫ�ȶ����ӽڵ�
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector< vector<int> > ans;
		if(root==NULL) return ans;
		vector<int> vec;
		stack<TreeNode *> st1;
		stack<TreeNode *> st2;
		st1.push(root);
		bool flag = true;
		TreeNode *curr;
		while(!st1.empty() || !st2.empty()){
			stack<TreeNode*> &sa = flag?st1:st2;
			stack<TreeNode*> &sb = flag?st2:st1;
			curr = sa.top();
			sa.pop();
			vec.push_back(curr->val);
			if(flag){
				if(curr->left) sb.push(curr->left);
				if(curr->right) sb.push(curr->right);
			}else{
				if(curr->right) sb.push(curr->right);
				if(curr->left) sb.push(curr->left);
			}
			if(sa.empty()) {
				ans.push_back(vec);
				vec.clear();
				flag = !flag;
			}
		}
		return ans;
    }
};