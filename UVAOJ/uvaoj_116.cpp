//注意只有一列时行尾不能输出空格否则presentation error

#include <cstdio>
#include <cstring>

const int MAX_M(11);
const int MAX_N(101);

int N;	//列
int M;	//行
int graph[MAX_M][MAX_N];
int result[MAX_M][MAX_N];

inline int min(int a,int b,int c){
		a = a>b?b:a;
		return a>c?c:a;
}

int main(){
	freopen("data.txt","r",stdin);
	while(scanf("%d %d",&M,&N) !=EOF ){
		memset(graph,0,sizeof(graph));
		memset(result,0,sizeof(result));
		for(int i=0;i<M;++i){
			for(int j=0;j<N;++j){
				scanf("%d",&graph[i][j]);
			}
		}
		for(int row = 0;row<M;++row){
			result[row][N-1] = graph[row][N-1];
		}
		for(int col = N-2;col>=0;--col){
			for(int row = 0;row<M;++row){
				int a(0); int b(result[row][col+1]);	int c(0);		//右上、右侧水平、右下
				//更好看，但是不一定更有效率
				//a = result[(row-1+M)%M][col+1];
				//c = result[(row+1)%M][col+1];
				if(row==0)   a = result[M-1][col+1];
				else		 a = result[row-1][col+1];
				if(row==M-1) c = result[0][col+1];
				else		 c = result[row+1][col+1];
				result[row][col] = graph[row][col] + min(a,b,c);
			}
		}
		int ans(1<<16);
		int start(0);
		for(int row = 0;row<M;++row){
			if (ans>result[row][0]){
				ans = result[row][0];
				start = row;
			}
		}
		int tmp(ans);
		for(int col=0;col<N;++col){
			printf("%d",start+1);
			if(N>1) printf(" ");
			int r1(0); int r2(start); int r3(0);
			if(start==0) r1 = M-1;
			else		 r1 = start-1;
			if(start==M-1) r3 = 0;
			else		   r3 = start+1;
			tmp -= graph[start][col];
			if(result[r1][col+1] != tmp) r1=1<<30;
			if(result[r2][col+1] != tmp) r2=1<<30;
			if(result[r3][col+1] != tmp) r3=1<<30;
			start = min(r1,r2,r3);
			if(col==N-2){
				printf("%d",start+1);
				break;
			}
		}
		printf("\n");
		printf("%d\n",ans);
	}
	return 0;
}
