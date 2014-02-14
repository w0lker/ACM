#include <cstdio>
#include <cstring>

int m,n;
int count;
bool oil[111][111];
bool viewed[111][111];
int offset[8][2]={-1,-1,-1,0,-1,1,0,1,0,-1,1,-1,1,0,1,1};

void dfs(int row,int col){
	for(int i=0;i<8;++i){
		//for(int j=0;j<2;++j){
			int r = row+offset[i][0];
			int c = col+offset[i][1];
			if(r>0 && r<m+1 && c>0 && c<n+1 && !viewed[r][c]){
				viewed[r][c]=true;
				if(oil[r][c]) dfs(r,c);
			}
		//}
	}
}

int main(){
	freopen("data.txt","r",stdin);
	while(scanf("%d %d",&m,&n)){
		if(!m) break;
		getchar();
		memset(viewed,false,sizeof(viewed));
		memset(oil,false,sizeof(oil));
		for(int i=1;i<m+1;++i){
			char c;
			int j(1);
			for(;j<n+1;++j){
				scanf("%c",&c);
				oil[i][j] = (c=='*'?false:true);
			}
			getchar();
		}
		//深度优先遍历
		count = 0;
		for(int i=1;i<m+1;++i){
			for(int j=1;j<n+1;++j){
				if(viewed[i][j]) continue;
				viewed[i][j]=true;
				if(oil[i][j]) {
					dfs(i,j);
					++count;
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}