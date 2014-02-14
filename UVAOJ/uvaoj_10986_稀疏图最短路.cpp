//0.272

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

struct Edge{
	int u,v,w;
};
typedef pair<int,int> pii;

const int MAX_V = 20002;
const int MAX_E = 50005;
const int INF = 2e8;
int LOOP;
int n;	//点
int m;	//边
int S;	//起点编号
int T;	//终点编号
bool visit[MAX_V];
int d[MAX_V];
priority_queue<pii,vector<pii>,greater<pii> > q;
vector< vector<Edge> > edges;	//每个点的相邻点

int main(){
	//freopen("data.txt","r",stdin);
	scanf("%d",&LOOP);
	for(int loop = 1;loop<=LOOP;++loop){
		scanf("%d%d%d%d",&n,&m,&S,&T);
		for(int i=0;i<n;++i){
			vector< Edge > vec;
			edges.push_back(vec);
		}
		int a,b,c;
		for(int i=0;i<m;++i){
			scanf("%d%d%d",&a,&b,&c);
			Edge e1; e1.u=a;e1.v =b;e1.w=c;
			edges[a].push_back(e1);
			Edge e2; e2.u=b;e2.v=a;e2.w=c;
			edges[b].push_back(e2);
		}
		memset(visit,false,sizeof(visit));
		for(int i=0;i<n;++i) d[i] = i==S?0:INF;
		q.push(make_pair(d[S],S));
		while(!q.empty()){
			pair<int,int> p = q.top();
			q.pop();
			int u = p.second;
			if(visit[u]) continue;
			visit[u] = true;
			for(int i=0;i<edges[u].size();++i){
				int v = edges[u][i].v;
				d[v] = min(d[v],d[u]+edges[u][i].w);
				q.push(make_pair(d[v],v));
			}
		}
		printf("Case #%d: ",loop);
		if(d[T]==INF) printf("unreachable\n");
		else		  printf("%d\n",d[T]);
		edges.clear();
	}
	return 0;
}


