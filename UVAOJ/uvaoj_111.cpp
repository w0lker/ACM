
//题目完全看错了，input中的4 2 3 1表示的第一个事件放在第4个位置，第二事件放在第2的位置...而不是通常所理解的。

#include <cstdio>
#include <cstring>
#include <algorithm>

using std::max;

const int MAX(30);
int N;
int eventOrder1 [MAX];
int eventOrder2 [MAX];
int length[MAX][MAX];

//int LCS();
int LCS(int i,int j);
int main(){
	freopen("data.txt","r",stdin);
	scanf("%d",&N);
	int loca;
	for(int i(1);i<=N;++i){
		scanf("%d",&loca);
		eventOrder1[loca] = i;
	}
	while(scanf("%d",&loca)==1){
		eventOrder2[loca] = 1;
		for(int i(2);i<=N;++i){
			scanf("%d",&loca);
			eventOrder2[loca] = i;
		}
		memset(length,0,sizeof(length));
		printf("%d\n",LCS(N,N));
	}
		return 0;
}


int LCS(int i,int j){
	int &ans = length[i][j];
	if(i==0 || j==0 || ans>0) return ans;
	if(eventOrder1[i]==eventOrder2[j])
		ans = 1+LCS(--i,--j);
	else{
		ans = max(LCS(i-1,j),LCS(i,j-1));
	}
	return ans;
}




//用迭代代替递归
int LCS(){
	int dp[MAX][MAX];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			if(eventOrder1[i]==eventOrder2[j]){
				dp[i][j] = dp[i-1][j-1]+1;
			}else{
				dp[i][j] = std::max(dp[i-1][j],dp[i][j-1]);				
			}
		}
	}
	return dp[N][N];
}