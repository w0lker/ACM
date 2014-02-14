#include<cstdio>
#include<cstring>
	
const int max = 55;		//最大的颜色个数

int t;
int n;
bool ans;
int graph[max][max];
int in[max];

void euler(int from);

int main(){
	//freopen("data.txt","r",stdin);
	scanf("%d",&t);
	for(int loop=0;loop<t;){
		memset(graph,0,sizeof(graph));
		memset(in,0,sizeof(in));
		ans = true;
		scanf("%d",&n);
		int a,b;
		while(n--){
			scanf("%d %d",&a,&b);
			++graph[a][b];
			graph[b][a] = graph[a][b];
			++in[a];
			++in[b];
		}
		for(int i=0;i<max;++i){
			if(in[i]%2!=0) {
				ans = false;
				break;
			}
		}
		printf("case #%d\n",++loop);
		if(!ans) printf("some beads may be lost\n");
		else{
			euler(a);
		}
		printf("\n");
	}

	return 0;
}


void euler(int from){
	for(int to=0;to<max;++to){
		if(graph[from][to]){
			--graph[from][to];	//不能写成--graph[to][from];因为from和to可能是同一个点
			graph[to][from] = graph[from][to];
			printf("%d %d\n",from,to);
			euler(to);
		}
	}
}