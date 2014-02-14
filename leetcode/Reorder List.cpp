#include <cstddef>		//引入NULL

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode *head1;
	ListNode *head2;
	void cut(ListNode *head);
	ListNode* reverse(ListNode *head);
	ListNode* merge();
public:
    void reorderList(ListNode *head) {
		if(head==NULL || head->next==NULL) return;
        cut(head);
		head2 = reverse(head2);
		head = merge();
		int a = 3;
    }
};

//从中间点切开，分成两半
void Solution::cut(ListNode *head){
	ListNode *p1=head,*p2=head,*tmp=head;
	if(head==NULL || head->next==NULL) return;
	if(head->next->next==NULL) {
		head1 = head;
		head2 = head->next;
		head1->next = NULL;
		return;
	}
	while(p2!=NULL && p2->next!=NULL ){
		tmp = p1;
		p1 = p1->next;
		p2 = p2->next->next;
	}
	tmp->next = NULL;
	head1 = head;
	head2 = p1;
}

ListNode * Solution::reverse(ListNode *head){
	if(head==NULL || head->next==NULL) return head;
	ListNode *p1 = head,*tmp = head;
	ListNode *p2 = p1->next;
	p1->next = NULL;
	while(true){
		tmp = p2->next;
		p2->next = p1;
		p1 = p2;
		if((p2 = tmp) == NULL) break;
	}
	return p1;
}

ListNode* Solution::merge(){
	ListNode *head = head1,*tmp = head1,*tmp2 =head2;
	while(head1!=NULL && head2!=NULL){
			tmp = head1->next;
			tmp2 = head2->next;
			head1->next = head2;
			head1 = tmp;
			if(tmp!=NULL) head2->next = head1;
			head2 = tmp2;
	}
	return head;
}


//测试数据：
//Solution s;
//ListNode *head = new ListNode(2);
//ListNode *l1 = new ListNode(5);ListNode *l2 = new ListNode(4);ListNode *l3 = new ListNode(9);
//ListNode *l4 = new ListNode(11);ListNode *l5 = new ListNode(7);ListNode *l6 = new ListNode(6);
//head->next = l1;
//l1->next = l2;
//l2->next =l3;
//l3->next = l4;
//l4->next = l5;
//l5->next = l6;
//s.reorderList(head);