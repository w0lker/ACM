#include <cstdio>  
#include <cstring>  
#include <cstdlib>  
#include <algorithm>  

//
//#include <iostream>
//using namespace std;
//
const int MAX = 123;
int N1;
int N2;
char path1[MAX];
char path2[MAX];
int result[MAX][MAX];

inline int max(int a,int b){
	return a>b?a:b;
}

int dp(int i,int j){
	if(i==-1 || j==-1 ) return 0;	//一定要放在最前面否则引用result[i][j]会导致未定义的结果!!!
	int &ans = result[i][j];
	if(ans>-1) return ans;
	ans = 0;
	if(path1[i]==path2[j]) return ans = 1+dp(i-1,j-1);
	else				   return ans = max(dp(i-1,j),dp(i,j-1));
}

int main(){
	int loop = 0;
	//freopen("data.txt","r",stdin);
	while(gets(path1) && path1[0]!='#'){
		gets(path2);
		N1 = strlen(path1);		N2 = strlen(path2);
		memset(result,-1,sizeof(result));
		printf("Case #%d: you can visit at most %d cities.\n", ++loop, dp(N1-1,N2-1));  
	}
	return 0;
}
