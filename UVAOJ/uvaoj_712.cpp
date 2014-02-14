/*
基本解法：
用一个大数组表示从根节点到叶节点，然后根据节点是1还是0决定取做左节点（2^n+1)还是右节点（2^n+2)

其他解法1：
blog.csdn.net/bluecat56/article/details/10391227
把二叉树看成二进制位，最高节点决定了是在叶节点的前1/2还是后1/2，
根节点左节点决定了落在叶节点的前0~1/4还是1/4~1/2以此类推，把各节点累加起来

其他解法2：


**/

#include <iostream>
#include <map>

using namespace std;

int n;
int m;
char nodes[256];
//char order[8][2];
char z[8];	
map<char,int> order;

int main_712(){
	//
	//memset(nodes,0,256*sizeof(char));
	////memset(order,0,16*sizeof(char));
	//while( scanf("%d",&n) && n){
	//	cin.get();
	//	for(int i=0;i<n;++i){
	//		cin.get();
	//		char c;
	//		cin>>c;
	//		order[c]=i;
	//		cout<<c<<"--"<<i<<endl;
	//		cin.get();
	//	}
	//	for(int i=0;i<(1<<n);++i){
	//		cin>>nodes[i-1+(1<<n)];
	//	}
	//	cin>>m;
	//	for(int i=0;i<m;++i){
	//		for(int j=0;j<n;++j){

	//		}
	//	}
	//	for(int i=0;i+1<(1<<(1+n));++i){
	//			printf("%c",nodes[i]);
	//	}
	//}
	///*

	///*for(int i=0;i<8;++i){
	//			printf("%c,%c\n",order[i][0],order[i][1]);
	//	}*/
	//for(int i=0;i<a;++i){
	//	cin>>order[i][0];
	//	cin>>order[i][1];
	//	cin.get();
	//}
	//char nodes[256];
	//memset(nodes,0,256*sizeof(char));
	//int a;
	//cin>>a;
	//while(a--){
	//	
	//}*/
	system("pause");
	return 0;
}
