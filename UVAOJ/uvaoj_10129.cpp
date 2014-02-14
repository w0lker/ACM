
#include<cstdio>
#include<cstring>

const int MAX=30;

int T;
int n;
int graph[MAX][MAX];
int visit[MAX];
int in[MAX];
int out[MAX];
int start;
char tmp[1003];

void init();
bool is_possible();

int main(){
	//freopen("data.txt","r",stdin);
	scanf("%d",&T);
	while(T--){
		init();
		printf("%s\n",(is_possible()?"Ordering is possible.":"The door cannot be opened."));
	}
	return 0;
}

void init(){
	scanf("%d",&n);
		getchar();
		memset(graph,0,sizeof(graph));
		memset(tmp,'\0',sizeof(tmp));
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		memset(visit,0,sizeof(visit));
		int a(0);
		int b(0);
		while(n--){
			gets(tmp);
			a = tmp[0]-'a';
			b = tmp[strlen(tmp)-1]-'a';
			++graph[a][b];
			++out[a];
			++in[b];
			visit[a] = 1;
			visit[b] = 1;
		}
		start = a;
}


int get_singularity(){
	int cnt(0);
	for(int i=0;i<MAX;++i){
		if(in[i]==out[i]) continue;
		++cnt;
		if(in[i]<out[i]) start = i; 
	}
	return cnt;
}

//判断是否能从起点遍历所有点
void is_connected(int from){
	visit[from] = 0;
	for(int to=0;to<MAX;++to){
		if(graph[from][to] & visit[to]){
			is_connected(to);
		}
	}
}


bool is_possible(){
	int cnt = get_singularity();
	if(!(cnt==0 || cnt==2)) return false;
	is_connected(start);
	for(int i=0;i<MAX;++i){
		if(visit[i]>0) return false;	
	}
	return true;
}