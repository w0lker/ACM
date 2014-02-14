/**
基本解法：根据数组建树，然后递归求和，根节点刚好在数组的depth位置，然后左边-1，右边+1
		wrong answer了，但是我测了十几组数据都没有问题~~~~
其他解法：不建树，直接操作数组，地址：blog.csdn.net/bluecat56/article/details/10410613
**/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int piles[100];
static int depth;
struct Tree{
	explicit Tree(int i):val(i),left(NULL),right(NULL){}
	int val;
	Tree *left;
	Tree *right;
};

Tree* build_tree(int val,int d){
	Tree *tree = new Tree(val);
	if(cin>>val,val!=-1) tree->left = build_tree(val,d+1);
	if(cin>>val,val!=-1) tree->right = build_tree(val,d+1);
	
	if(d>depth) depth = d;
	return tree;
}

void fall(Tree *tree,int loc){
	piles[loc]+=tree->val;
	if(tree->left) fall(tree->left,loc-1);
	if(tree->right) fall(tree->right,loc+1);
}

int main_699(){
	int val;
	int loop = 0;
	while(cin>>val && val!=-1){
		memset(piles,0,sizeof(piles));
		depth=0;
		Tree *root = build_tree(val,0);
		fall(root,depth);
		cout<<"Case "<<(++loop)<<":"<<endl;
		for(int i=0;i<2*depth+1;++i){
			if(piles[i]) cout<<piles[i]<<" ";
		}
		cout<<endl;
	}

	return 0;
}