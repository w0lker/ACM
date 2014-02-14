#include<cstdio>
#include<cstring>

const int N = 210;
const int R = 10001;
const char *msg1 = "Possible\n";
const char *msg2 = "Not Possible\n";

int road_num;
int node_num;
int graph[N][N];
int in[N];
int out[N];
bool visited[N];
bool ans;

bool has_singularity();
void check_connected(int);


int main(){
	//freopen("data.txt","r",stdin);
	while(scanf("%d %d",&node_num,&road_num)!=EOF){
		memset(graph,0,sizeof(graph));
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		memset(visited,false,node_num);
		ans = true;
		int a;
		int b;
		for(int i=0;i<road_num;++i){
			scanf("%d %d",&a,&b);
			++graph[a][b];
			++out[a];
			++in[b];
		}
		if(has_singularity()) {
			printf(msg2);
			continue;
		}
		check_connected(a);
		for(int i=0;i<node_num;++i){
			if(! visited[i]){
				ans = false;
				break;
			}
		}
		if(ans) printf(msg1);
		else   printf(msg2);
		
	}
	return 0;
}


bool has_singularity(){
	for(int i=0;i<node_num;++i){
		if(in[i]!=out[i]) return true;
	}
	return false;
}

void check_connected(int from){
	if(!ans) return;
	visited[from] = true;
	for(int to=0;to<node_num;++to){
		if(graph[from][to]){
			--graph[from][to];
			check_connected(to);
		}
	}
}