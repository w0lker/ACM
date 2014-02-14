	
#include <cstdio>
#include <cstring>

const int MAX = 1001;

int N;
int result[MAX];
bool graph[MAX][MAX];
int weight[MAX];
int iq[MAX];

int dp(int i){
	if(result[i]>0) return result[i];
	int &ans = result[i];
	ans = 1;
	for(int j=0;j<N;++j){
		if(graph[i][j]){
			int tmp = 1+dp(j);
			if(tmp>ans)	ans = tmp;
		}
	}
	return result[i];
}

int main(){
	//freopen("data.txt","r",stdin);
	memset(result,0,sizeof(result));
	memset(graph,false,sizeof(graph));
	memset(weight,0,sizeof(weight));
	memset(iq,0,sizeof(iq));
	int i = 0;
	while(scanf("%d %d",&weight[i],&iq[i])==2){
		for(int j=0;j<i;++j){
			if(weight[i]<weight[j] && iq[i]>iq[j]) graph[i][j] = true;
			if(weight[j]<weight[i] && iq[j]>iq[i]) graph[j][i] = true;
		}
		++i;
	}
	N = i;
	
	int ans = -1;
	int start = -1;
	for(int i=0;i<N;++i){
		int tmp = dp(i);
		if(tmp>ans){
			ans = tmp;
			start = i;
		}
	}
	printf("%d\n",ans);
	printf("%d\n",start+1);
	int tmp = ans;
	for(int i=1;i<ans;++i){
		for(int j=0;j<N;++j){
			if(graph[start][j] && result[j]==(tmp-1)){
				printf("%d\n",j+1);		
				--tmp;
				start = j;
				break;
			}
		}
	}
	return 0;
}
