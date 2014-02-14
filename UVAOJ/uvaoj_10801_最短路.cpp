/**
1��˼·�ܼ򵥣���ÿ�����ݡ�ÿ��ͣ����¥����һ�����ʾ�����µ�֮���weight�������µ�ʱ��������������л���ʱ��(60�룩
2�����ս���п����кü������ݶ��ܴﵽ��K�㣬��Ҫȡ����ֵ��С�ġ�
3��Ϊ�˷�����㡣����һ����ʼ�㣬������Щ���Ϊ0�ĵ��ݵ�weightΪ0.
4��ע���ȡ����ʱû��ʵ�ָ���ͣ�����ٸ�¥�㣬������Ҫͨ����ȡ��һ���ַ��ж��Ƿ�Ϊ���������������������и����壬�������һ��
������û�л��еģ�����Ҫ�ж���һ�ζ�ȡscanf("%d%c",&val,&c)�Ƿ�Ϊ�ա�
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
