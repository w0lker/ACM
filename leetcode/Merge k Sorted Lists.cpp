#include <vector>
#include <queue>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct Finger{
	Finger(int l,ListNode *y=NULL):LIndex(l),NIndex(y){}
	int LIndex;	//list index;
	ListNode *NIndex; //node lindex;
};
struct cmp{
	bool operator()(Finger &lhs,Finger &rhs){
		if(lhs.NIndex->val != rhs.NIndex->val) return rhs.NIndex->val < lhs.NIndex->val;
		else return rhs.LIndex < lhs.LIndex;
	}
};
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        std::priority_queue<Finger,vector<Finger>,cmp> p;
		for(int ijk=0;ijk<lists.size();++ijk){
			if(lists[ijk]!=NULL) p.push(Finger(ijk,lists[ijk])); 
		}
		if(p.empty()) return NULL;
		if(p.size()==1) return p.top().NIndex;
		ListNode *ans = p.top().NIndex;
		ListNode *curr;
		ListNode *node;
		int i,min;
		curr = ans;
		node = p.top().NIndex;
		i = p.top().LIndex;
		p.pop();
		while(true){
			min = p.top().NIndex->val;
			while(node->next!=NULL && node->next->val<=min){
				curr->next = node->next;
				curr = curr->next;
				node = node->next;
			}
			if(curr->next!=NULL) p.push(Finger(i,curr->next));
			node = p.top().NIndex;
			i = p.top().LIndex;
			p.pop();
			curr->next = node;
			curr = curr->next;
			 if(p.empty()){
				 while(node->next!=NULL){
					curr->next = node->next;
					curr = curr->next;
					node = curr;
				 }
				 break;
			 }
		}
		return ans;
    }
};

//²âÊÔÊý¾Ý
//ListNode *a = new ListNode(2);
//	a->next = new ListNode(5);a->next->next= new ListNode(7);a->next->next->next = new ListNode(9);
//	ListNode *b = new ListNode(1);
//	b->next = new ListNode(2);b->next->next= new ListNode(5);
//	ListNode *c = new ListNode(4);
//	c->next = new ListNode(6);c->next->next= new ListNode(6);c->next->next->next = new ListNode(7);
//	vector<ListNode *> vec; vec.push_back(a);vec.push_back(b);vec.push_back(c);
//	Solution s;
//	ListNode *ans = s.mergeKLists(vec);
//	while(ans!=NULL) cout<<ans->val<<" ";
//	cout<<endl;