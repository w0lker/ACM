#define NULL 0
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
	void testIsSameTree(TreeNode *p, TreeNode *q,bool &notSame){
		if(notSame || (p==NULL && q==NULL))  return; 
		else if((p==NULL && q!=NULL) || (p!=NULL && q==NULL) || (p->val!=q->val)){
				notSame = true;
				return;
		}
		else{
			testIsSameTree(p->left,q->left,notSame);
			testIsSameTree(p->right,q->right,notSame);
		}
	}
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        bool notSame = false;
		testIsSameTree(p,q,notSame);
		return notSame?false:true;
    }
};

//Êý¾Ý
//TreeNode *r1 = new TreeNode(1);
//	TreeNode *r2 = new TreeNode(2);TreeNode *r3 = new TreeNode(5);
//	TreeNode *r4 = new TreeNode(2); TreeNode *r5 = new TreeNode(2);TreeNode *r6 = new TreeNode(5);
//	TreeNode *r7 = new TreeNode(4);
//
//	r1->left=r2;r1->right=r3;
//	r4->left = r5; r4->right = r6;
//	Solution s;
//	cout<<s.isSameTree(r1,r4)<<endl;