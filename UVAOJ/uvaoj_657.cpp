//疑问：点数X会不会出现在边界上，从而最先被读到。

#include <cstdio>
#include <cstring>
#include <algorithm>

int col,row;
bool view[55][55];
char pixel[55][55];
int number[55];
int die_index;
int offset[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

void dfs2(int i,int j){
	if (i<=0 || i>row || j<=0 || j>col) return;
	for(int m=0;m<4;++m){
		int new_i = i+offset[m][0];
		int new_j = j+offset[m][1];
		if(!view[new_i][new_j] && pixel[new_i][new_j]=='X'){
			view[new_i][new_j] = true;
			dfs2(new_i,new_j);
		}
		
	}
}

void dfs1(int i,int j){
	if (i<=0 || i>row || j<=0 || j>col) return;
	for(int m=0;m<4;++m){
		int new_i = i+offset[m][0];
		int new_j = j+offset[m][1];
		if(!view[new_i][new_j] && pixel[new_i][new_j]!='.'){
			view[new_i][new_j] = true;
			if(pixel[new_i][new_j]=='*'){
				dfs1(new_i,new_j);
			}
			else if(pixel[new_i][new_j]=='X') {
				dfs2(new_i,new_j);
				++number[die_index];
			}
		}
	}
}

int main(){
	//freopen("data.txt","r",stdin);
	int loop(0);
	while(scanf("%d %d",&col,&row)){
		if(!col) break;
		getchar();
		memset(view,false,sizeof(view));
		memset(pixel,'.',sizeof(pixel));
		memset(number,0,sizeof(number));
		die_index = 0;
		char ch;
		for(int i=1;i<row+1;++i){
			for(int j=1;j<col+1;++j){
				scanf("%c",&pixel[i][j]);	
				printf("%c",pixel[i][j]);	
			}
			getchar();
			printf("\n");
		}

		for(int i=1;i<row+1;++i){
			for(int j=1;j<col+1;++j){
				if(!view[i][j]){
					view[i][j] = true;
					if(pixel[i][j]=='*'){//num = 0;
						dfs1(i,j);
						++die_index;
					}
				}
			}
		}
		std::sort(number,number+die_index);
		printf("Throw %d\n",++loop);
		for(int i=0;i<die_index;++i){
			printf("%d ",number[i]);
		}
		printf("\n");

	}
	return 0;
}