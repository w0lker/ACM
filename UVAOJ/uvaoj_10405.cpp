#include <cstdio>
#include <cstring>

const int MAX = 1011;
int N1;		//字符1串实际长度
int N2;		//字符2串实际长度
char str1[MAX];
char str2[MAX];
int result[MAX][MAX];

inline int max(int a,int b){
	return a>b?a:b;
}

int dp(int i,int j){
	if(i==-1 || j==-1) return 0;
	if(result[i][j]>-1) return result[i][j];
	result[i][j] = 0;
	int &ans = result[i][j];
	if(str1[i]==str2[j]) 
		ans = 1+dp(i-1,j-1);
	else ans = max(dp(i-1,j),dp(i,j-1));
	return ans;
}

int main(){
	freopen("data.txt","r",stdin);
	while(gets(str1)){
		gets(str2);
		N1 = strlen(str1);
		N2 = strlen(str2);
		memset(result,-1,sizeof(result));
		for(int i(0);i<N1;++i){
			for(int j(0);j<N2;++j){
				if(str1[i]==str2[j]){
					if(i==0 || j==0){
						result[i][j] = 1;
						continue;
					}
					result[i][j] = 1+result[i-1][j-1];
				}else{
					int a(0);
					int b(0);
					if(i>0) a = result[i-1][j];
					if(j>0) b = result[i][j-1];
					result[i][j] = max(a,b);
				}
			}
		}
		printf("%d\n",result[N1-1][N2-1]);
		//也可以用递归
		//printf("%d\n",dp(N1-1,N2-1));
	}
	return 0;
}
