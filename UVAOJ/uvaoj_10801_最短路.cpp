/**
1、思路很简单，把每个电梯、每个停靠的楼层用一个点表示，上下点之间的weight就是上下的时间或者两个电梯切换的时间(60秒）
2、最终结果中可能有好几个电梯都能达到第K层，需要取其中值最小的。
3、为了方便计算。增加一个开始点，他到那些起点为0的电梯的weight为0.
4、注意读取数据时没有实现给出停靠多少个楼层，所以需要通过读取下一个字符判断是否为换行来结束，但是其中有个陷阱，就是最后一组
数据是没有换行的，所以要判断下一次读取scanf("%d%c",&val,&c)是否为空。
**/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX_N = 5;
const int MAX_K = 101;
const int INF = 1e8;
int N;
int K;
int T[MAX_N];
int stop_num[MAX_N];
int fno[MAX_N*MAX_K];
int d[MAX_K*MAX_N];
bool visit[MAX_K*MAX_N];
int graph[MAX_K*MAX_N][MAX_K*MAX_N];
int num_v;
int num_e;

void init(){
	num_v = 0;
	memset(fno,0,sizeof(fno));
	memset(d,0,sizeof(d));
	memset(visit,false,sizeof(visit));
	for(int i=0;i<MAX_K;++i) 
		for(int j=0;j<MAX_K;++j)
			graph[i][j] = (i==j?0:INF);
}

void read_data(){
	num_v =	1;
	memset(stop_num,0,sizeof(stop_num));
	for(int i=0;i<N;++i) scanf("%d",&T[i]); 
	for(int i=0;i<N;++i){
		char c;
		int val;
		int j = 0;
		while(scanf("%d%c",&val,&c)!=EOF){
			fno[num_v++] = val;
			++stop_num[i];
			if(c=='\n') break;
		}
	}
}

int main(){
	freopen("data.txt","r",stdin);
	while( (scanf("%d%d",&N,&K)!=EOF)){
		init();
		read_data();
		int state = 0;
		for(int i=0;i<N;++i){
			for(int j=1;j<stop_num[i];++j){
				int a = j + state+1;
				int time = (fno[a]-fno[a-1])*T[i];
				graph[a][a-1] = graph[a-1][a] = time;
			}
			state += stop_num[i];
		}
		for(int i=1;i<num_v;++i){
			for(int j=i+1;j<num_v;++j){
				if((fno[i]==fno[j]) && (fno[i]!=0)){
					graph[i][j] = graph[j][i] = 60;
				}
			}
		}
		state = 1;
		for(int i=0;i<N;++i){
			if(fno[state]==0){
				graph[state][0] = graph[0][state] = 0;
			}
			state += stop_num[i];
		}
		for(int i=0;i<num_v;++i) d[i] = i==0?0:INF;
		for(int i=0;i<num_v;++i){
			int x;
			int m=INF;
			for(int i=0;i<num_v;++i) if(!visit[i] && d[i]<m) m=d[x=i];
			visit[x] = true;
			for(int i=0;i<num_v;++i){
				if(!visit[i]){
					d[i] = std::min(d[i],d[x]+graph[x][i]);
				}
			}
		}
		int ans = INF;
		for(int i = 1;i<num_v;++i)
			if(fno[i]==K){
				if(d[i]<ans) ans = d[i];
			}
		if(ans==INF) printf("IMPOSSIBLE\n");
		else		printf("%d\n",ans);
	}
	return 0;
}
