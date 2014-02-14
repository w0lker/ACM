
//直接利用merge list进行归并排序
#define NULL 0
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);
public:
    ListNode *sortList(ListNode *head) {
		if(head==NULL || head->next==NULL) return head;
		ListNode *fast=head,*slow=head;
		while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
			slow = slow->next;	
			fast = fast->next->next;
		}
		ListNode *head2 = slow->next;
		slow->next = NULL;
		return mergeTwoLists(sortList(head),sortList(head2));
    }
};

ListNode * Solution::mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1==NULL) return l2;
		if(l2==NULL) return l1;
		int maxVal;
		ListNode *small,*big,*ans,*pre;
		if(l1->val>=l2->val){
			maxVal = l1->val;
			small = l2;
			big = l1;
		}else{
			maxVal = l2->val;
			small = l1;
			big = l2;
		}
		ans = small;
		while(true){
			pre = small;
			while(small!=NULL && small->val<=maxVal){
				pre = small;
				small = small->next;
			}
			pre->next = big;
			if(small==NULL) break;
			//交换大小指针
			pre = big;
			big = small;
			small = pre;
			maxVal = big->val;
		}
		return ans;
    }