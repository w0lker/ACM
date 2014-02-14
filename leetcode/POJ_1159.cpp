//从两侧开始往中间递归
//当两侧字母不同时，选择在左侧插入或者在右侧插入，选择结果较小的。
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
const int LIMIT = 5005;
char str[LIMIT];
short int dp[LIMIT][LIMIT];

int dfs(int low,int up){
	if(low>=up) return 0;
	if(dp[low][up]>-1) return dp[low][up];
	if(str[low]==str[up]) return dp[low][up] = dfs(low+1,up-1);
	else				  return dp[low][up] = 1 + min(dfs(low+1,up),dfs(low,up-1));
}

int main(){
	freopen("data.txt","r",stdin);
	while(scanf("%d",&N)!=EOF){	
		scanf("%s",str);
		memset(dp,-1,sizeof(dp));
		printf("%d\n",dfs(0,N-1));
	}
	return 0;
}

//迭代
int main(){
	freopen("data.txt","r",stdin);
	while(scanf("%d",&N)!=EOF){	
		scanf("%s",str+1);
		memset(dp,0,sizeof(dp));
		for(int i=N;i>=1;--i){
			for(int j=i+1;j<=N;++j){
				if(str[i]==str[j]) dp[i][j] = dp[i+1][j-1];
				else dp[i][j] = 1 + min(dp[i+1][j],dp[i][j-1]);
			}
		}
		printf("%d\n",dp[1][N]);
	}
	return 0;
}

//迭代 滚动数组	没搞懂！！！！！！！！！！！！
#include<iostream>
#include<string.h>
#include<string>
using namespace std;
short DP[2][5003];

int main(){
    int n;
    string str;

    while(scanf("%d",&n)!=EOF){
        cin>>str;
        memset(DP,0,sizeof(DP));

        int k= 0;
        for(int i=n-2;i>=0;i--){     
            for(int j=i;j<n;j++){
                if(str[i]==str[j]) 
                    DP[k][j] = DP[1-k][j-1];
                else
                    DP[k][j] = min(DP[1-k][j],DP[k][j-1]) + 1;
            }
            for(int j=0;j<n;j++) DP[1-k][j] = 0;  
            k = 1 - k;  // 循环利用的关键值k。
        }
        printf("%d\n",DP[1-k][n-1]); 
    }
    return 0;
}