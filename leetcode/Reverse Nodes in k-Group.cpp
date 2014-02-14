//大牛的解法，很简介
class Solution {
	ListNode *reverse(ListNode *pre,ListNode *next){
		ListNode *last = pre->next;
		ListNode *curr = last->next;
		while(curr!=next){
			last->next = curr->next;
			curr->next = pre->next;
			pre->next = curr;
			curr = last->next;
		}
		return last;
	}
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(k<=1 || head==NULL) return head;
		ListNode *dumpy = new ListNode(0);
		dumpy->next = head;
		int i = 1;
		ListNode *pre = dumpy;
		while(head!=NULL){
			if(i%k==0){
				pre = reverse(pre,head->next);
				head = pre->next;
			}else{
				head = head->next;
			}
			++i;
		}
		return dumpy->next;
    }
};
//最基本的解法,找出每个区间的头尾，revere，链接到前面一个list
//k可以假设小于链表长度
#define NULL 0
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(k<=1 || head==NULL) return head;
		ListNode dumpy(0);
		dumpy.next = head;
		ListNode *tail = &dumpy;
		ListNode *pre,*curr,*tmp,*nextHead;
		while(true){
			ListNode *h = tail->next;
			ListNode *t = h;
			for(int i=0;i<k-1 && t!=NULL;++i)
				t = t->next;
			if(t==NULL) break;
			else{
				nextHead = t->next;
				///////////交换头尾指针////////
				pre=h,curr=h->next;
				while(true){
					tmp = curr->next;
					curr->next = pre;
					pre = curr;
					curr = tmp;
					if(pre==t) break;
				}
				tmp = h;
				h = t;
				t = tmp;
				////////////////////////////////
				tail->next = h;
				tail = t;
				tail->next = nextHead;
			}
		}
		return dumpy.next;
    }
};