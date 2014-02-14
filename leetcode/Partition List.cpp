//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//巧解1：增加两个dumpy头结点，这样可以省略掉很多NULL的判断
//用两组指针small_h small_t、big_h big_t分别记录小于x和大于等于x的节点
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *small_h = new ListNode(-1);
		ListNode *small_t = small_h;
		ListNode *big_h = new ListNode(-1);
		ListNode *big_t = big_h;
		ListNode *curr = head;
		while(curr!=NULL){
			if(curr->val<x){
				small_t->next = curr;
				small_t = curr;
			}else{
				big_t->next = curr;
				big_t = curr;
			}
			curr = curr->next;
		}
		small_t->next = big_h->next;
		big_t->next = NULL;
		return small_h->next;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//最蠢得方法,各种分类讨论
#define NULL 0
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *curr = head,*pre = head;
		ListNode *head2 = NULL,*tail2 = NULL;
		ListNode *ans = NULL;
		while(curr!=NULL && curr->val>=x) {
			pre = curr;
			curr = curr->next;
		}
		if(curr==NULL) return head;
		if(curr!=head){
			head2 = head;
			tail2 = pre;
		}
		while(curr!=NULL){
			if(curr->val>=x){
				pre->next = curr->next;
				if(head2==NULL){
					head2 = tail2 = curr;
				}else{
					tail2->next = curr;
					tail2 = curr;
				}
				curr = curr->next;
			}else{
				if(ans==NULL) ans = curr;
				pre = curr;
				curr = curr->next;
			}
		}
		if(head2!=NULL){
			pre->next = head2;
			tail2->next = NULL;
		}
		return ans;
    }
};