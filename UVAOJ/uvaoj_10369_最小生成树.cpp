/**
只有两个站点都有卫星设备时二者才能无视距离进行通讯，所以s个卫星可以拿掉长度最长的s个边
**/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_V = 505;
const int MAX_E = MAX_V*MAX_V/2+2;

struct Point{
	int x,y;
};
struct Edge{
	int u,v;
	double w;
};

int T;
int S;
int P;
int p[MAX_V];
Point points[MAX_V];
Edge edges[MAX_E];

double dist(const Point *pa,const Point *pb){
	return sqrt(pow(pa->x-pb->x,2.0)+pow(pa->y-pb->y,2.0));
}
int comp(const Edge &e1,const Edge &e2){
	return e1.w<e2.w;
}
int find(int x){
	return x==p[x]?x:p[x]=find(p[x]);
}

int main(){
	freopen("data.txt","r",stdin);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&S,&P);
		for(int i=1;i<=P;++i){
			scanf("%d%d",&points[i].x,&points[i].y);
			p[i] = i;
		}
		int num = 0;
		for(int i=1;i<=P;++i)
			for(int j=i+1;j<=P;++j){
				edges[num].u = i;
				edges[num].v = j;
				edges[num].w = dist(&points[i],&points[j]);
				++num;
			}
		std::sort(edges,edges+num,comp);
		int transNum = P - S;	//实际上是 (p-1) - (s-1)
		int cnt = 0;
		for(int i=0;i<num;++i){
			int pu = find(edges[i].u);
			int pv = find(edges[i].v);
			if(pu!=pv){
				p[pv] = pu;
				++cnt;
				if(cnt==transNum){	    //注意不能拿i和transNum比
					printf("%.2lf\n",edges[i].w);
					break;
				}
			}
		}
	}
	return 0;
}