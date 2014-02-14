//www.ahathinking.com/archives/173.html#more-173
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//动态规划 迭代
#include <cstdio>
#include <cstring>

int T;
const int LIMIT = 202;
char s1[LIMIT],s2[LIMIT],s3[2*LIMIT];
int dp[LIMIT][LIMIT];

int main(){
	//freopen("data.txt","r",stdin);
	scanf("%d",&T);	
	for(int loop=1;loop<=T;++loop){
		scanf("%s%s%s",s1,s2,s3);
		getchar();
		int m = strlen(s1);
		int n = strlen(s2);
		memset(dp,0,sizeof(dp));
		dp[0][0] = 1;
		for(int i=0;i<=m;++i){
			for(int j=0;j<=n;++j){
				if(i>=1 && s1[i-1]==s3[i+j-1] && dp[i-1][j])
					dp[i][j] = 1;
				if(j>=1 && s2[j-1]==s3[i+j-1] && dp[i][j-1])
					dp[i][j] = 1;
			}
		}
		printf("Data set %d: %s\n",loop,(dp[m][n])?"yes":"no");
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//递归 动态规划
#include <cstdio>
#include <cstring>

int T;
const int LIMIT = 202;
char s1[LIMIT],s2[LIMIT],s3[2*LIMIT];
int dp[LIMIT][LIMIT];

bool isMatch(int m,int n);

int main(){
	//freopen("data.txt","r",stdin);
	scanf("%d",&T);	
	for(int i=1;i<=T;++i){
		scanf("%s%s%s",s1,s2,s3);
		int m = strlen(s1);
		int n = strlen(s2);
		memset(dp,-1,sizeof(dp));
		dp[0][0] = 1;
		printf("Data set %d: %s\n",i,(isMatch(m,n)?"yes":"no"));
	}
	return 0;
}

bool isMatch(int m,int n){
	if(dp[m][n]>-1) return dp[m][n];
	bool a = false,b = false;
	if(m>0 && s1[m-1]==s3[m+n-1] ) a = isMatch(m-1,n);
	if(n>0 && s2[n-1]==s3[m+n-1] ) b = isMatch(m,n-1);
	return dp[m][n]=(a||b);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
//递归搜索  超时
#include <cstdio>

bool isMatch(char *s1,char *s2,char *s3);

int main(){
	const int LIMIT = 202;
	//freopen("data.txt","r",stdin);
	int T;
	scanf("%d",&T);	
	char s1[202],s2[202],s3[202];
	//cout<<(*(s1+1)=='\0')<<" "<<((s1+1)==NULL)<<endl;
	for(int i=1;i<=T;++i){
		scanf("%s%s%s",s1,s2,s3);
		printf("Data set %d: %s\n",i,(isMatch(s1,s2,s3)?"yes":"no"));
	}
	return 0;
}

bool isMatch(char *s1,char *s2,char *s3){
	if(*s3=='\0') return true;
	bool a = false,b = false;
	if(*s1!='\0'  && *s1==*s3) a = isMatch(s1+1,s2,s3+1);
	if(*s2!='\0'  && *s2==*s3) b = isMatch(s1,s2+1,s3+1);
	return a||b;
}