/**
slow和pre只在一种情况下二者相同，即要remove的是head
**/
#define NULL 0
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(n==0 || head==NULL) return head;
		ListNode *slow=head,*fast=head,*pre=head;
		for(int i=0;i<n;++i) fast = fast->next;
		while(fast!=NULL){
			pre = slow;
			fast = fast->next;
			slow = slow->next;
		}
		if(pre==head && slow==head) return head->next;
		pre->next = pre->next->next;
		return head;
    }
};