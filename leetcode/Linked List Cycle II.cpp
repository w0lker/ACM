#define NULL 0
	struct ListNode {
	 int val;
	 ListNode *next;
	 ListNode(int x) : val(x), next(NULL) {}
	};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *p1 = head,*p2 = head;
		bool no_cycle = true;
		while(p2 && p2->next){
			p1 = p1->next;
			p2 = p2->next->next;
			if(p1==p2){
				no_cycle = false;
				break;
			}
		}
		if(no_cycle) return NULL;
		p2 = head;
		while(p2!=p1){
			p1 = p1->next;
			p2 = p2->next;
		}
		return p1;
    }
};

//²âÊÔÊý¾Ý£º
	//ListNode *head = new ListNode(40);
	//ListNode *n1 = new ListNode(6); ListNode *n2 = new ListNode(1);
	//ListNode *n3 = new ListNode(8); ListNode *n4 = new ListNode(2);
	//ListNode *n5 = new ListNode(5);ListNode *n6 = new ListNode(4);
	//head->next = n1;n1->next=n2;n2->next =  n3;n3->next = n4;n4->next=n5;n5->next=n5;
	//Solution s;
	//ListNode *ans = s.detectCycle(head);
	//if(ans) cout<<ans->val<<endl;