/**
Bellman-Food方法,更新完n-1次后若还能更新说明有负回路。
**/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

struct Edge{
	int u,v,w;
};

const int INF = 2e8;
const int MAX_V = 10001;
const int MAX_E = 20002;
int T;
int n;
int m;
int d[MAX_V];
Edge edges[MAX_E];

int main(){
	freopen("data.txt","r",stdin);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;++i){
			scanf("%d%d%d",&edges[i].u,&edges[i].v,&edges[i].w);
		}
		for(int i=0;i<n;++i) d[i]=INF;
		int i=0;
		for(;i<n;++i){
			bool stop = true;
			for(int e=0;e<m;++e){
				if(d[edges[e].v]>d[edges[e].u]+edges[e].w){
					d[edges[e].v] = d[edges[e].u]+edges[e].w;
					stop = false;
				}
			}
			if(stop) { 
				break;
			}
		}
		printf("%s\n",i==n?"possible":"not possible");
	}
	return 0;
}


