//在四周添加高度极大的值可以省去边界检查
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x7fffffff;

int T;
int row;
int col;
int dp[104][104];
int graph[104][104];
char name[50];

int change[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

int search(int r,int c){
	if(dp[r][c]>-1) return dp[r][c];
	int &ans = dp[r][c];
	ans = 0;
	int tmp = 0;
	for(int i=0;i<4;++i){
		int r2 = r + change[i][0];
		int c2 = c +change[i][1];
		if(graph[r][c]>graph[r2][c2]){
			tmp = 1 + search(r2,c2);
			ans = max(ans,tmp);
		}
	}
	if(ans>0){
		int aa = 0;
	}

	return ans;
}

int main(){
	//freopen("data.txt","r",stdin);
	scanf("%d",&T);
	while(T--){
		memset(name,0,sizeof(name));
		memset(dp,-1,sizeof(dp));
		scanf("%s %d %d",name,&row,&col);
		for(int i=0;i<=col+1;++i){
			graph[0][i] = INF;
			graph[row+1][i] = INF;
		}
		for(int i=0;i<=row+1;++i){
			graph[i][0] = INF;
			graph[i][col+1] = INF;
		}
		for(int i=1;i<=row;++i){
			for(int j=1;j<=col;++j){
				scanf("%d",&graph[i][j]);
			}
		}
		int max = -1;
		int tmp;
		for(int i=1;i<=row;++i){
			for(int j=1;j<=col;++j){
				tmp = search(i,j);
				if(tmp>max) max = tmp;
			}
		}
		printf("%s: %d\n",name,max+1);
	}
	return 0;
}