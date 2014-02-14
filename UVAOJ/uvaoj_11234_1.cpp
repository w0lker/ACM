/**
给定一个字符串：
 读取一个字符：
	若是数字x： 直接push(x),
	若是操作符O：a = pop; b=pop; push(b O a)

给出字符串str1,求str2
使得：算法作用在stack和str1上面
等价于算法作用在queue和str2上面

解法：
	先将逆波兰式变成一个二叉树，然后得到二叉树的层次遍历，再将其逆序输出即可
	构建二叉树的方法：读取逆波兰式遇到数字（小写字母）入栈，遇到操作符（大写字母）
	则pop两个数字，作为他的左右子树	将根节点压入栈，以此类推。

测试结果： 12685815	11234	Expressions	Accepted	C++	0.209	2013-11-16 15:05:26

问题：每次运算建的二叉树没有销毁，内存泄漏！
**/
#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;

struct Tree{
	Tree(const char c):value(c),left(NULL),right(NULL){}
	char value;
	Tree *left;
	Tree *right;
};


int main_11234_1()
{
	int num;
	cin>>num;
	cin.get();
	while(num--){
		stack<Tree*> stk;
		string exp;
		getline(cin,exp);
		for(size_t i=0;i!=exp.size();++i){
			char c = exp[i];
			Tree *tree = new Tree(c);
			if(c>90)	stk.push(tree);
			else{
				Tree *r = stk.top();
				stk.pop();
				Tree *l = stk.top();
				stk.pop();
				tree->left=l;
				tree->right=r;
				stk.push(tree);
			}
		}
		//层次遍历
		Tree *root = stk.top();
		queue<Tree*> q;
		q.push(root);
		size_t i=exp.size()-1;
		while(!q.empty()){
			Tree *tree = q.front();
			q.pop();
			if(tree->left) q.push(tree->left);
			if(tree->right) q.push(tree->right);
			exp[i--]=tree->value;
		}
		cout<<exp<<endl;
	}
	
    return 0;
}