#include <cstdio>
#include <cstring>

const int MAX = 101;
int N1;
int N2;
int tow1[MAX];
int tow2[MAX];
int result[MAX][MAX];
int loop;

inline int max(int a,int b){
	return a>b?a:b;
}

int dp(int i,int j){
	int &ans = result[i][j];
	if(ans>-1) return ans;
	if(i==N1 || j==N2) return 0;
	if(tow1[i]==tow2[j]){
		ans = 1+dp(i+1,j+1);
	}else{
		ans = max(dp(i+1,j),dp(i,j+1));
	}
	return ans;
}

int main(){
	//freopen("data.txt","r",stdin);
	loop = 0;
	while(scanf("%d %d",&N1,&N2) && (N1 || N2) ){
		memset(result,-1,sizeof(result));
		for(int i=0;i<N1;++i){
			scanf("%d",&tow1[i]);
		}
		for(int i=0;i<N2;++i){
			scanf("%d",&tow2[i]);
		}
		printf("%s%d\n","Twin Towers #",++loop);
		printf("%s%d\n\n","Number of Tiles : ",dp(0,0));
	}
	return 0;
}
