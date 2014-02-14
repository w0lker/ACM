//������ķ�����push(root) push(NULL) Ȼ��ÿ������NULLʱpushһ��NULL���ɡ�

//��cnt1��¼��ǰlevel�ĸ��� cnt2��¼��һlevel�Ľڵ����
//cnt1��Ϊ0ʱ��vec����������Ȼ�󽻻�cnt1 cnt2;
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector< vector<int> > ans;
		if(root==NULL) return ans;
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
				ans.push_back(vec);
				vec.clear();
				swap(cnt1,cnt2);
			}
		}
		return ans;
    }
};