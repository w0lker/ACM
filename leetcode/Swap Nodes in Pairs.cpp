struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
		if(head==NULL) return head;
        ListNode *pre = head,*f1 = head,*f2 = head->next;
		ListNode *ans = (f2==NULL)?f1:f2;
		while(f2!=NULL){
			pre->next = f2;
			f1->next = f2->next;
			f2->next = f1;
			pre = f1;
			f1 = f1->next;
			if(f1==NULL) break;
			f2 = f1->next;
		}
		return ans;
    }
};