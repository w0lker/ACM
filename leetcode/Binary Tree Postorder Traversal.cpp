/**
����Ҫ���������Ϣ��һ�ַ����ǰ�treenode�ۺϳ��µ�node�����������visied��Ϣ��
��һ�ַ�����
��һ��flag�����ס�Ƿ�Ϊ�ڶ��η���ĳ�ڵ㣬����ǵڶ��η�����ֱ��pop��������ǵ�һ�η��ʿ������ӽڵ��Ƿ�Ϊ�գ�
��Ϊ��Ҳֱ��pop����Ϊ��������ӽڵ�push������Ȼ��push���������������ӽڵ㡣
Ҳ����������stack��ʵ��
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
//��һ�ַ�������pre����¼֮ǰ�����ʹ��ĵ㣬��ô������ĳ�ڵ�ʱ��pre�պ����������ӽڵ�
//˵���ýڵ�������������ϣ����Խ���pop����

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