#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

struct Point{
	int x,y;
};

struct Edge{
	int u,v;
	double w;
};

const int MAX_V = 752;
const int MAX_E = 300000;
int N;
int M;
int p[MAX_V];
Edge edges[MAX_E];
Point points[MAX_V];
map<int,int> old_cables;

//注意distance函数和xutility头文件中的函数重名了。
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
	//bool flag = false;
	while(scanf("%d",&N)!=EOF){
		memset(edges,0,sizeof(edges));
		old_cables.clear();
		for(int i=1;i<=N;++i){
			scanf("%d %d",&points[i].x,&points[i].y);
			p[i] = i;
		}
		scanf("%d",&M);
		for(int i=0;i<M;++i){
			int u,v;
			scanf("%d %d",&u,&v);
			old_cables[u] = v;
			old_cables[v] = u;
			int parentU = find(u);
			int parentV = find(v);
			if(parentV!=parentU) p[parentV]=parentU;
			//p[u] = v;	//错误的语句可能导致死循环
		}
		int index = 0;
		map<int,int>::iterator iter;
		for(int i=1;i<=N;++i)
			for(int j=i+1;j<=N;++j){
				iter = old_cables.find(i);
				if(iter!=old_cables.end() && (*iter).first==i && (*iter).second==j) continue;
				edges[index].u = i;
				edges[index].v = j;
				edges[index].w = dist(&points[i],&points[j]);
				++index;
			}
		std::sort(edges,edges+index,comp);
		double ans = 0.0;
		for(int i=0;i<index;++i){
			int parentU = find(edges[i].u);
			int parentV = find(edges[i].v);
			if(parentU!=parentV){
				p[parentV] = parentU;
				ans += edges[i].w;
				//printf("%d %d %f\n",edges[i].u,edges[i].v,edges[i].w);
			}
		}
		/*if(flag) printf("\n");	//这种画蛇添足的打印换行方法是错误的。
		else flag = true; */
		printf("%.2lf\n",ans);
	}
	return 0;
}