#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_M = 12882;
const int MAX_N = 3404;
int M,N;
int dp[2][MAX_M];
int weight[MAX_N];
int rate[MAX_N];

int main(){
	freopen("data.txt","r",stdin);
	scanf("%d%d",&N,&M);
	memset(dp,0,sizeof(dp));
	weight[0] = rate[0] = 0;
	for(int i=1;i<=N;++i){
		scanf("%d%d",&weight[i],&rate[i]);
	}
	bool flag = true;
	int curr,pre;
	for(int i=1;i<=N;++i){
		if(flag) {
			pre = 0;
			curr = 1;
		}else{
			pre = 1;
			curr = 0;
		}
		flag = !flag;
		for(int j=1;j<=M;++j){
			if(j<weight[i]) dp[curr][j] = dp[pre][j];
			else 			dp[curr][j] = max(rate[i]+dp[pre][j-weight[i]],dp[pre][j]);
		}
	}
	printf("%d",dp[curr][M]);
	return 0;
}