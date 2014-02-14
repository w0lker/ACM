/**
注意结果数组不能设成1000*1000，那样会超时，只要开到50就行，
改用索引代替位置进行DP就可以了。
**/
#include <cstdio>
#include <cstring>

int L;
int N;
int loca[55] = {0};
int result[55][55];

inline int max(int a,int b){
	return a>b?a:b;
}

int dp(int i,int j);

int main(){
	//freopen("data.txt","r",stdin);
	while(scanf("%d",&L) && L){
		scanf("%d",&N);
		memset(result,-1,sizeof(result));
		for(int i=1;i<=N;++i){
			scanf("%d",&loca[i]);
		}
		loca[0] = 0;
		loca[N+1] = L;
		printf("The minimum cutting is %d.\n",dp(0,N+1));
	}
	return 0;
}


int dp(int index_a,int index_b){
	int i = loca[index_a];
	int j = loca[index_b];
	int &ans = result[index_a][index_b];
	if(ans>-1) return ans;
	ans = 1<<30;
	for(int k=1;k<=N;++k){
		if(loca[k]>i && loca[k]<j){
			int tmp = j-i+dp(index_a,k)+dp(k,index_b);
			if(tmp<ans) ans = tmp;
		}
	}
	if(ans==1<<30) ans = 0;
	return ans;
}