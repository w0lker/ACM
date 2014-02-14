//更简洁的做法，每次移动一下，分别和l1、l2比较，插入较小的node

//移动指针，直到small指针大于当前较大值
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
			//交换大小指针
			pre = big;
			big = small;
			small = pre;
			maxVal = big->val;
		}
		return ans;
    }
};