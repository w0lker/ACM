//�ⷨ2�� �ö���ָ��
//�ⷨ3�� �ò��뷨���൱����������

//������ֳ�����,���м�һ��reverse֮������������
#define NULL 0
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m==n) return head;
		ListNode *root = new ListNode(0);
		root->next = head;
		ListNode *curr=root,*pre,*tmp;
		ListNode *tail1,*head2,*tail2,*head3;
		int i=0;
		for(;i<m-1;++i) curr = curr->next;
		tail1 = curr;
		curr = curr->next;
		tail2 = curr;
		pre = curr;
		curr = curr->next;
		++i;
		for(;i<n;++i){
			tmp = curr->next;
			curr->next = pre;
			pre = curr;
			curr = tmp;
		}
		head2 = pre;
		head3 = curr;
		tail1->next = head2;
		tail2->next = head3;
		return root->next;
    }
};