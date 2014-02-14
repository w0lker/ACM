//把list的元素拷贝到vector里面，居然也AC了。
#include <vector>
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
	TreeNode *help(vector<int> &num,int low,int up){
		int mid = (low+up)/2;
		TreeNode *node = new TreeNode(num[mid]);
		if(low==up) return node;
		if(mid>low) node->left = help(num,low,mid-1);
		if(mid<up) node->right = help(num,mid+1,up);
		return node;
	}
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(head==NULL) return NULL;
		vector<int> vec;
		while(head!=NULL) {
			vec.push_back(head->val);
			head = head->next;
		}
		return help(vec,0,vec.size()-1);
    }
};

//解法2 直接操作链表，不用辅助空间
class Solution {
private:
	TreeNode *help(ListNode *head,int num){
		ListNode *mid = head;
		for(int i=0;i<num/2;++i) mid = mid->next;
		TreeNode *root = new TreeNode(mid->val);
		if(num==1) return root;
		root->left = help(head,num/2);
		if(num>2) root->right = help(mid->next,(num+1)/2-1);
		return root;
	}
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(head==NULL) return NULL;
		int num = 0;
		ListNode *finger = head;
		while(finger!=NULL){
			++num;
			finger = finger->next;
		}
		help(head,num);
    }
};
//解法3 用快慢指针寻找终点，不需要传递长度
//但是会破坏链表结构：www.cnblogs.com/TenosDoIt/p/3440079.html

