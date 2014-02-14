//������������ÿ���ƶ�һ�£��ֱ��l1��l2�Ƚϣ������С��node

//�ƶ�ָ�룬ֱ��smallָ����ڵ�ǰ�ϴ�ֵ
#define NULL 0
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
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
			//������Сָ��
			pre = big;
			big = small;
			small = pre;
			maxVal = big->val;
		}
		return ans;
    }
};