/**
����һ���ַ�����
 ��ȡһ���ַ���
	��������x�� ֱ��push(x),
	���ǲ�����O��a = pop; b=pop; push(b O a)

�����ַ���str1,��str2
ʹ�ã��㷨������stack��str1����
�ȼ����㷨������queue��str2����

�ⷨ��
	�Ƚ��沨��ʽ���һ����������Ȼ��õ��������Ĳ�α������ٽ��������������
	�����������ķ�������ȡ�沨��ʽ�������֣�Сд��ĸ����ջ����������������д��ĸ��
	��pop�������֣���Ϊ������������	�����ڵ�ѹ��ջ���Դ����ơ�

���Խ���� 12685815	11234	Expressions	Accepted	C++	0.209	2013-11-16 15:05:26

���⣺ÿ�����㽨�Ķ�����û�����٣��ڴ�й©��
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
		//��α���
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