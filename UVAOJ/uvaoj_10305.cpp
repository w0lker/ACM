/**
dfs，处理当前节点所有下游节点（还没处理的），处理完后push当前节点到stack中。
**/

#include<cstdio>
#include<cstring>
#include <queue>
#include <stack>

using std::queue;
using std::stack;

const int MAX = 101;
int task_num;		//task num
int rela_num;		//relation num
int graph[MAX][MAX];
int in[MAX];
bool visited[MAX];
stack<int> ans;
void dfs(int s);

int main(){
	//freopen("data.txt","r",stdin);
	while(scanf("%d %d",&task_num,&rela_num) && !(task_num==0 && rela_num==0)){
		memset(graph,0,sizeof(graph));
		memset(in,0,sizeof(in));
		memset(visited,false,sizeof(visited));
		int a,b;
		while(rela_num--){
			scanf("%d %d",&a,&b);
			++graph[a][b];
			++in[b];
		}
		for(int i =1;i<=task_num;++i){
			if(!in[i]) dfs(i);
		}
		while(!ans.empty()){
			int tmp = ans.top();
			ans.pop();
			printf("%d",tmp);
			if(!ans.empty()) printf(" ");
		}
		printf("\n");
	}
	return 0;
}


void dfs(int s){
	if(visited[s]) return;
	visited[s] = true;
	for(int i=1;i<=task_num;++i){
		if(graph[s][i] && !visited[i]){
			--graph[s][i];
			dfs(i);
		}
	}
	ans.push(s);
}