#define NULL 0
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *root = new ListNode(-1);
		root->next = head;
		ListNode *pre=root,*curr=head;
		ListNode *search;
		while(curr!=NULL){
			search = curr;
			while(search!=NULL && search->val==curr->val){
				search = search->next;
			}
			if(curr->next==search){	//curr½ÚµãÎ¨Ò»
				pre = curr;
				curr = search;
			}else{
				pre->next = search;
				curr = search;
			}
		}
		return root->next;
    }
};