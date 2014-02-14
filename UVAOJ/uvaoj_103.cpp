#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAX_D = 10;
const int MAX_B = 30;

struct Box{
	int edges[MAX_D];
};

int dim;
int N;
Box boxes[MAX_B];
bool graph[MAX_B][MAX_B];
int result[MAX_B];
int output[MAX_B];
int max_stack_num;

inline int max(int a,int b){
	return a>b?a:b;
}

bool contain(const Box &out,const Box &in){
	for(int i(0);i<dim;++i){
		if(out.edges[i]<=in.edges[i]) return false;
	}
	return true;
}

int dp(int i){
	if(result[i]>0) return result[i];
	result[i] = 1;
	int &ans = result[i];
	for(int j(0);j<N;++j){
		if(j==i) continue;
		if(graph[i][j]){
			ans = max(ans,dp(j)+1);
		}
	}
	return ans;
}


void back(int i,int len){
	if(len==0) return;
	for(int j(0);j<N;++j){
		if(j==i) continue;
		if(graph[i][j] && result[j]==len-1){
			back(j,result[j]);
			break;
		}
	}
	printf("%d",i+1);
	if(len==max_stack_num) printf("\n");
	else printf(" ");
}

int main(){
	freopen("data.txt","r",stdin);
	while(scanf("%d %d",&N,&dim)==2){
		memset(boxes,0,sizeof(boxes));
		memset(graph,0,sizeof(graph));
		memset(result,0,sizeof(result));
		for(int i(0);i<N;++i){
			for(int j(0);j<dim;++j){
				scanf("%d",&boxes[i].edges[j]);
			}
		}

		for(int i(0);i<N;++i){
			std::sort(boxes[i].edges,boxes[i].edges+dim);
		}

		for(int i(0);i<N;++i){
			for(int j(0);j<N;++j){
				if (j==i) continue;
				graph[i][j] = contain(boxes[i],boxes[j]);
			}
		}
		//动态规划求各点的最长路径
		max_stack_num = 0;
		int start(-1);
		for(int i(0);i<N;++i){
			int tmp = dp(i);
			if(max_stack_num<tmp){
				max_stack_num = tmp;
				start = i;
			}
		}
		printf("%d\n",max_stack_num);
		//回溯输出节点
		back(start,max_stack_num);
	}
	return 0;
}
