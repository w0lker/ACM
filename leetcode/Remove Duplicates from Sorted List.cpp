#define NULL 0
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
		ListNode *curr = head;
		ListNode *search;
		while(curr!=NULL){
			search = curr;
			while(search!=NULL && search->val==curr->val){
				search = search->next;
			}
			//if(curr!=search) curr->next = search;
			curr->next = search;
			curr = curr->next;
		}
		return head;
    }
};