/**
解决版本1的内存泄漏！
http://www.cppblog.com/rakerichard/archive/2011/04/13/144111.html
http://blog.csdn.net/shuangde800/article/details/7707123
**/
//#include<iostream>
//#include<stack>
//#include<queue>
//#include<string>
//using namespace std;
//
//struct Tree{
//	Tree(const char c):value(c),left(NULL),right(NULL){}
//	char value;
//	Tree *left;
//	Tree *right;
//};
//
//Tree trees[10001];
//
//int main()
//{
//	int num;
//	cin>>num;
//	cin.get();
//	while(num--){
//		stack<Tree*> stk;
//		string exp;
//		getline(cin,exp);
//		for(size_t i=0;i!=exp.size();++i){
//			char c = exp[i];
//			Tree *tree = new Tree(c);
//			if(c>90)	stk.push(tree);
//			else{
//				Tree *r = stk.top();
//				stk.pop();
//				Tree *l = stk.top();
//				stk.pop();
//				tree->left=l;
//				tree->right=r;
//				stk.push(tree);
//			}
//		}
//		//层次遍历
//		Tree *root = stk.top();
//		queue<Tree*> q;
//		q.push(root);
//		size_t i=exp.size()-1;
//		while(!q.empty()){
//			Tree *tree = q.front();
//			q.pop();
//			if(tree->left) q.push(tree->left);
//			if(tree->right) q.push(tree->right);
//			exp[i--]=tree->value;
//		}
//		cout<<exp<<endl;
//	}
//	
//    return 0;
//}