/**
不用queue的话需要一个map保存任意两点之间的距离
**/

#include <cstdio>
#include <cstring>
#include <queue>

using std::queue;

struct Cell{
	Cell(int a=0,int b=0,int c=0):row(a),col(b),len(c){};
	int row;
	int col;
	int len;
};

Cell start;
Cell end;
queue<Cell> path;
bool view[8][8];
int offset[8][2]={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};

int bfs(){
	int r = path.front().row;
	int c = path.front().col;
	int l = path.front().len;
	view[r][c] = true;
	path.pop();
	if(r==end.row && c==end.col){
		while(!path.empty()) path.pop();
		return l;
	}
	else{
		for(int i=0;i<8;++i){
			int new_r = r+offset[i][0];
			int new_c = c+offset[i][1];
			if(new_r>=0 && new_r<8 && new_c>=0 && new_c<8 && !view[new_r][new_c]){
				Cell ce(new_r,new_c,l+1);
				path.push(ce);
			}
		}
	}
	return -1;
}
int main(){
	//freopen("data.txt","r",stdin);
	char c1,c2;
	int i1,i2;
	while(scanf("%c%d %c%d",&c1,&i1,&c2,&i2)!=EOF){
		memset(view,false,sizeof(view));
		int depth(0);
		getchar();
		start.col = c1-'a';
		start.row = i1-1;
		end.col = c2-'a';
		end.row = i2-1;
		path.push(start);
		while(!path.empty()){
			depth = bfs();
			if(path.empty()) break;
		}
		printf("To get from %c%d to %c%d takes %d knight moves.\n",
				(start.col+'a'),(start.row+1),(end.col+'a'),(end.row+1),depth);
	}
	return 0;
}