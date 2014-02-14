struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
		if(head==NULL) return NULL;
		RandomListNode *origin = head;
		RandomListNode *copy,*ans;
		//�����µĵ㣬�����嵽ԭ�ȵ�list��
		while(origin!=NULL){
			copy = new RandomListNode(origin->label);
			copy->next = origin->next;
			origin->next = copy;
			origin = copy->next;
		}
		//����randomָ��
		origin = head;
		copy = head->next;
		while(true){
			copy->random = (origin->random==NULL)?NULL:origin->random->next;
			origin = copy->next;
			if(origin==NULL) break;
			copy = origin->next;
		}
		//��list�ϳ�����
		origin = head;
		ans = copy = head->next;
		while(true){
			origin->next = copy->next;
			origin = origin->next;
			if(origin==NULL) break;
			copy->next = origin->next;
			copy = copy->next;
		}
		return ans;
    }
};

//RandomListNode *n1 = new  RandomListNode(2);RandomListNode *n2 = new  RandomListNode(9);
// RandomListNode *n3 = new  RandomListNode(4);
// RandomListNode *n4 = new  RandomListNode(1);RandomListNode *n5 = new  RandomListNode(6);
//// n1->next = n2;n2->next=n3;n3->next=n4;n4->next=n5;
// //n1->random = n2; n2->random =n1;//n3->random= n2;n4->random =n4;n5->random=NULL;
//Solution sol;
//RandomListNode *ans = sol.copyRandomList(n1);