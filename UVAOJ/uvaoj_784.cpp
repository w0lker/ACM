
#include <cstdio>
#include <cstring>

int n;
char maze[35][85];
int row,col;
int pos_i,pos_j;
int offset[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int row,int col){
	for(int i=0;i<4;++i){
		int r = row+offset[i][0];
		int c = col+offset[i][1];
		if(maze[r][c]==' '){
			maze[r][c]='*';
			dfs(r,c);
		}
	}
}

int main_784(){
	scanf("%d",&n);
	getchar();
	while(n--){
		memset(maze,'\0',sizeof(maze));
		row =0,col=0;
		char ch;
		int i=0,j=0;
		while(scanf("%c",&ch)){
			if(ch=='\n'){
				++i;
				j=0;
				continue;
			}else if(ch=='_'){
				gets(maze[i]);
				break;
			}else if(ch=='*'){
				pos_i = i;
				pos_j = j;
			}
			maze[i][j++] = ch;
		}
		row = i+1;
		dfs(pos_i,pos_j);
		for(int i=0;i<row;++i){
			for(int j=0;;++j){
				if(!maze[i][j]) break;
				printf("%c",maze[i][j]);
			}
			printf("\n");
		}
	}
	
	return 0;
}