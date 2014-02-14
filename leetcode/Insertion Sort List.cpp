//添加以个dumpy的头结点会更方便点
#define NULL 0
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
		if(head==NULL) return head;
        ListNode *pre,*curr,*finger=head->next;
		while(finger!=NULL){
			pre = head;
			curr = head->next;
			if(finger->val<head->val){
				while(pre->next!=finger)
					pre = pre->next;
				pre->next = finger->next;
				finger->next = head;
				head = finger;
				finger = pre->next;
			}else{
				while(curr!=finger && curr->val<=finger->val){
					pre = curr;
					curr = curr->next;
				}
				if(curr!=finger){
					while(curr->next!=finger)
						curr = curr->next;
					curr->next = finger->next;
					finger->next = pre->next;
					pre->next = finger;
				}
				finger = curr->next;
			}
		}
		return head;
    }
};