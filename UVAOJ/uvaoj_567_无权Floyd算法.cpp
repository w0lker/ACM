#include <cstdio>
#include <cstring>
#include <algorithm>

int N;
int rst[21][21];
bool graph[21][21];
int T;
const int INF = 10000;

int main(){
	freopen("data.txt","r",stdin);
	int a;
	int b;
	int index;
	T = 0;
	while(scanf("%d",&a)!=EOF){
		memset(graph,false,sizeof(graph));
		for(index=1;index<20;++index){
			for(int i=0;i<a;++i){
				scanf("%d",&b);
				graph[index][b] = true;
				graph[b][index] = true;
			}
			if(index<19) scanf("%d",&a);
		}
		memset(rst,0,sizeof(rst));
		for(int i=1;i<=20;++i)
			for(int j=1;j<=20;++j)
				if(i==j) rst[i][j]=0;
				else if(graph[i][j]) rst[i][j]=1;
				else rst[i][j] = INF;
		for(int k=1;k<=20;++k)
			for(int i=1;i<=20;++i)
				for(int j=1;j<=20;++j)
					if(rst[i][k]<INF && rst[k][j]<INF) rst[i][j] = std::min(rst[i][j],rst[i][k]+rst[k][j]);
		printf("Test Set #%d\n",++T);
		scanf("%d",&N);
		while(N--){
			scanf("%d %d",&a,&b);
			printf("%2d to %2d: %d\n",a,b,rst[a][b]);
		}
		printf("\n");
	}
	return 0;
}