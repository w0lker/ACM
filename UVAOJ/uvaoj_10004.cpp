#include<cstdio>
#include<cstring>
#include<queue>

using std::queue;

int n;
int e;
bool ans;
bool graph[222][222];
int color[222];
queue<int> nodes;

void bfs();

int main(){
	freopen("data.txt","r",stdin);
	while(scanf("%d",&n) && n){
		scanf("%d",&e);
		memset(graph,false,sizeof(graph));
		memset(color,0,sizeof(color));
		ans = true;
		int na,nb;
		while(e--){
			scanf("%d %d",&na,&nb);
			graph[na][nb]=true;
			graph[nb][na]=true;
		}
		bfs();
		printf("%s\n",(ans?"BICOLORABLE.":"NOT BICOLORABLE."));
	}
	return 0;
}

void bfs(){
	color[0]=1;
	nodes.push(0);
	while(!nodes.empty()){
		int index = nodes.front();
		nodes.pop();
		for(int i=0;i<n;++i){
			if(graph[index][i]){
				if(color[index]==color[i]){			//颜色相重了
					ans = false;
					while(!nodes.empty()) nodes.pop();
					return ;
				}
				if(!color[i]){	//未涂色
					nodes.push(i);
					color[i] = (color[index]==1?2:1);
				}

			}
		}

	}
}