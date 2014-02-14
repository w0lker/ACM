#define NULL 0
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ans = new ListNode(0);
		ListNode *curr = ans,*pre = ans;
		int carry = 0;
		while(l1!=NULL || l2!=NULL){
			int sum = (l1==NULL?0:l1->val)+(l2==NULL?0:l2->val)+carry;
			if(sum>=10){
				carry = 1;
				sum %= 10;
			}else carry = 0;
			curr->val = sum;
			ListNode *node = new ListNode(0);
			curr->next = node;
			pre = curr;
			curr = curr->next;
			if(l1!=NULL) l1=l1->next;
			if(l2!=NULL) l2=l2->next;
		}
		if(carry){
			curr->val = 1;
		}else{
			pre->next = NULL;
		}
		return ans;
    }
};

//ListNode *l1  = new ListNode(3);ListNode *l2  = new ListNode(4);ListNode *l3  = new ListNode(2);
//	l1->next = l2;l2->next = l3;
//	ListNode *n1  = new ListNode(9);ListNode *n2  = new ListNode(0);ListNode *n3  = new ListNode(8);ListNode *n4  = new ListNode(9);
//	n1->next = n2;n2->next=n3;n3->next=n4;