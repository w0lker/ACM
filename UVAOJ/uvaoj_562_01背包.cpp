#include <cstdio>  
#include <cstring>  
#include <algorithm>
using namespace std;


//解法2：转化成0 1背包问题
int T;
int n;	//硬币个数
int result[101][501];
int coins[101];

inline int max(int a,int b){ return a>b?a:b;}

int dp(int i,int j){	//阶段i,剩余容量为j
	if(i>=n || j<coins[i]) return 0;
	int &ans = result[i][j];
	if(ans>-1) return ans;
	ans = max(dp(i+1,j),coins[i]+dp(i+1,j-coins[i]));
	return ans;
}

int main(){
	freopen("data.txt","r",stdin);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int sum = 0;
		for(int i=0;i<n;++i){
			scanf("%d",&coins[i]);
			sum+=coins[i];
		}
		sort(coins,coins+n);
		memset(result,-1,sizeof(result));
		printf("%d\n",abs(2*dp(0,sum/2)-sum));
	}
	return 0;
}

/**
#include <cstdio>  
#include <cstring>  
#include <algorithm>
using namespace std;


//解法2：转化成0 1背包问题
int t;
int n;	//硬币个数
int result[101][501];
int coins[101];

inline int max(int a,int b){ return a>b?a:b;}

int dp(int i,int j){	//阶段i,剩余容量为j
	if(i>=n || j<coins[i]) return 0;
	int &ans = result[i][j];
	if(ans>-1) return ans;
	ans = max(dp(i+1,j),coins[i]+dp(i+1,j-coins[i]));
	return ans;
}

int main(){
	freopen("data.txt","r",stdin);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int sum = 0;
		for(int i=0;i<n;++i){
			scanf("%d",&coins[i]);
			sum+=coins[i];
		}
		sort(coins,coins+n);
		memset(result,0,sizeof(result));
		int half = sum/2;
		for(int i=n;i>=0;--i){
			for(int j = 0;j<=half;++j){
				if(i==n || j<coins[i] ) result[i][j]=0;
				else result[i][j] = max(result[i+1][j],result[i+1][j-coins[i]]+coins[i]);
			}
		}
		printf("%d\n",abs(2*result[0][half]-sum));
	}
	return 0;
}

**/



//解法1：
//先用已有硬币进行组合,判断1~sum/2之间那些数字可以组合出来，然后再求其中使二者之和最小的即可

//const int LIMIT = 50001;
//int T;
//bool ans[LIMIT];
//int coins[101];
//
//int main(){
//	freopen("data.txt","r",stdin);
//	scanf("%d",&T);
//	int n;	//硬币个数
//	while(T--){
//		scanf("%d",&n);
//		int sum = 0;
//		for(int i=0;i<n;++i){
//			scanf("%d",&coins[i]);
//			sum+=coins[i];
//		}
//		sort(coins,coins+n);
//		memset(ans,false,sizeof(ans));
//		ans[0] = true;
//		for(int i=0;i<n;++i){
//			for(int j=sum;j>=coins[i];--j){
//				if(ans[j-coins[i]]) ans[j] = true;
//			}
//		}
//		int min = 1<<16;
//		int dev = 0;
//		for(int i=0;i<sum/2+1;++i){
//			if(ans[i]){
//				dev = abs(2*i-sum);
//				if(dev<min){
//					min = dev;
//				}
//			}
//		}
//		printf("%d\n",min);
//	}
//	return 0;
//}
