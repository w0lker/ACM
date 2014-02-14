///tail连到head上，然后再k%len 处断开链就行了。
#define NULL 0
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
		int len = 1;
		ListNode *pre,*end;
		ListNode *curr = head->next;
		while(curr!=NULL){
			++len;
			pre = curr;
			curr = curr->next;
		}
		end = pre;
		k %= len;
		if(k==0) return head;
		pre = head;
		curr = head;
		for(int i=0;i<=k;++i)
			curr = curr->next;
		while(curr!=NULL){
			pre = pre->next;
			curr = curr->next;
		}
		end->next = head;
		head = pre->next;
		pre->next = NULL;
		return head;
    }
};