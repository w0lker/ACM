//0.159

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>

using std::pair;
using std::priority_queue;
using std::greater;
using std::make_pair;
using std::vector;

typedef pair<int,int> pii;

const int MAX_V = 20002;
const int MAX_E = 2*50005;
const int INF = 2e8;
int LOOP;
int n;	//点
int m;	//边
int S;	//起点编号
int T;	//终点编号
bool visit[MAX_V];
int d[MAX_V];
priority_queue<pii,vector<pii>,greater<pii> > q;
int from[MAX_E];
int to[MAX_E];
int weight[MAX_E];
int next[MAX_E];
int head[MAX_V];

int main(){
	freopen("data.txt","r",stdin);
	scanf("%d",&LOOP);
	for(int loop = 1;loop<=LOOP;++loop){
		scanf("%d%d%d%d",&n,&m,&S,&T);
		m *= 2;
		memset(from,0,sizeof(from));
		memset(to,0,sizeof(to));
		memset(visit,false,sizeof(visit));
		for(int i=0;i<n;++i) d[i] = i==S?0:INF;
		for(int i=0;i<n;++i) head[i] = -1;
		int a,b,c;
		for(int e=0;e<m;++e){
			scanf("%d%d%d",&a,&b,&c);
			from[e]=a;to[e]=b;weight[e]=c;
			next[e] = head[from[e]];
			head[from[e]] = e;
			++e;
			from[e]=b;to[e]=a;weight[e]=c;
			next[e] = head[from[e]];/**/
			head[from[e]] = e;
		}
		q.push(make_pair(d[S],S));
		while(!q.empty()){
			pair<int,int> p = q.top();
			q.pop();
			int u = p.second;
			if(visit[u]) continue;
			visit[u] = true;
			for(int e=head[u];e!=-1;e=next[e]){
				if(d[to[e]]>d[u]+weight[e]){
					d[to[e]] = d[u]+weight[e];
					q.push(make_pair(d[to[e]],to[e]));
				}
			}
		}
		printf("Case #%d: ",loop);
		if(d[T]==INF) printf("unreachable\n");
		else		  printf("%d\n",d[T]);
	}
	return 0;
}


