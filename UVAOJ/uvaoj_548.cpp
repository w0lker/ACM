/**
	注意：所有节点的值都是不一样的
	解法：先建树 后 遍历。 遍历时遇到叶节点时比较当前值和最小值
**/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

int in[10000];
int post[10000];
int min_sum=1<<31-1;
int min_leaf=10000;
struct Tree{
	Tree(int i):value(i),left(NULL),right(NULL){}
	int value;
	Tree *left;
	Tree *right;
};

void sum(Tree *tree,int pre_sum){
	pre_sum+=tree->value;
	if(tree->left==NULL && tree->right==NULL){
		if(pre_sum<min_sum){
			min_sum = pre_sum;
			min_leaf = tree->value;
		}
		if(pre_sum==min_sum && tree->value<min_leaf) min_leaf = tree->value;
	}
	if(tree->left!=NULL) sum(tree->left,pre_sum);
	if(tree->right!=NULL) sum(tree->right,pre_sum);
}
Tree* build_tree(int i_begin,int i_end,int p_begin,int p_end){	
	Tree *father = new Tree(post[p_end]);
	int pos = i_begin;
	while(in[pos]!=post[p_end]) ++pos;
	if(pos>i_begin) father->left = build_tree(i_begin,pos-1,p_begin,p_begin+(pos-1-i_begin));
	if(pos<i_end) father->right = build_tree(pos+1,i_end,p_end-(i_end-pos),p_end-1);
	return father;
}

void extract(string str,vector<int> &vec){
	istringstream in(str);
	int tmp;
	while(in>>tmp) vec.push_back(tmp);
}


int main_548(){
	int tmp,index=0,i;
    char blank;
	while(scanf("%d",&tmp)!=EOF){
		blank = getchar();
		in[index++]=tmp;
		if(blank=='\n'){	//换行了，读取后续表达式
			for(i=0;i<index;i++) cin>>post[i];
			//建树
			Tree *root = build_tree(0,index-1,0,index-1);
			//深度优先遍历
			sum(root,0);
			cout<<min_leaf<<endl;
			//清空：
			index=0;
			min_sum=1<<31-1;
			min_leaf=10000;
		}
	}
	return 0;
}





//另外的读取数据的方法：
void get_data(){
	string str1,str2;
	vector<int> vec1;
	vector<int> vec2;
	while(getline(cin,str1)){
		extract(str1,vec1);
		getline(cin,str2);
		extract(str2,vec2);
		int t = vec1.size();
		//其他计算。。。。
		vec1.clear();vec2.clear();
	}
}
