/**
打印函数不好做
**/
#include <cstdio>  
#include <cstring>  

const int LIMIT = 21;
const int LIMIT2 = 10000;

int C;	//最大容量( N minutes)
int N;	// tracks 个数
int v[LIMIT];	//每个track的时长
int dp[LIMIT][LIMIT2];
int dp2[LIMIT][LIMIT2];		//用于输出的

inline int max(int a,int b){return a>b?a:b;}
void print(int i,int num){
	if(num<=0) return;
	if (i==N-1 && dp2[i][num]) {
		printf("%d ",dp2[i][num]);
		return;
	}
	if(dp2[i][num]){
		printf("%d ",dp2[i][num]);
		print(i+1,num-dp2[i][num]);
	}else{
		print(i+1,num);
	}
}

int main(){
	freopen("data.txt","r",stdin);
	while(scanf("%d",&C)!=EOF){
		scanf("%d",&N);
		memset(v,0,sizeof(v));
		memset(dp2,false,sizeof(dp2));
		for(int i=0;i<N;++i){
			scanf("%d",&v[i]);
		}
		for(int i=N-1;i>=0;--i){
			for(int j=0;j<=C;++j){		//j<=C而不是j<C
				if(i==N-1){
					dp[i][j] = 0;
				}else{
					dp[i][j] = dp[i+1][j];
				}
				if(j>=v[i]){
					int tmp =dp[i+1][j-v[i]]+v[i];
					if(tmp>dp[i][j]){
						dp[i][j] = tmp;
						dp2[i][j] = v[i];
					}
				}
			}
		}
		int ans = dp[0][C];
		print(0,C);
		printf("sum:%d\n",ans);
	}
	return 0;
}