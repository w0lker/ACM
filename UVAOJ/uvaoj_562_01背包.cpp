#include <cstdio>  
#include <cstring>  
#include <algorithm>
using namespace std;


//�ⷨ2��ת����0 1��������
int T;
int n;	//Ӳ�Ҹ���
int result[101][501];
int coins[101];

inline int max(int a,int b){ return a>b?a:b;}

int dp(int i,int j){	//�׶�i,ʣ������Ϊj
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


//�ⷨ2��ת����0 1��������
int t;
int n;	//Ӳ�Ҹ���
int result[101][501];
int coins[101];

inline int max(int a,int b){ return a>b?a:b;}

int dp(int i,int j){	//�׶�i,ʣ������Ϊj
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



//�ⷨ1��
//��������Ӳ�ҽ������,�ж�1~sum/2֮����Щ���ֿ�����ϳ�����Ȼ����������ʹ����֮����С�ļ���

//const int LIMIT = 50001;
//int T;
//bool ans[LIMIT];
//int coins[101];
//
//int main(){
//	freopen("data.txt","r",stdin);
//	scanf("%d",&T);
//	int n;	//Ӳ�Ҹ���
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
