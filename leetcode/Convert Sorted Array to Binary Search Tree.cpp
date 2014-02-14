//��һ������������е�����{4,2,5,1,3}  ��˵Ҳ��ƽ����������������������ȡ����
//�м�Ԫ����Ϊ���ڵ������ȷ��������
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