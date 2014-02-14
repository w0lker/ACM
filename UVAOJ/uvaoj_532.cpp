/**
只要添加一个维度就好，其他跟二维是一样一样的。
**/

#include <cstdio>
#include <cstring>
#include <queue>

using std::queue;

struct Cell{
	Cell(int a=0,int b=0,int x=0,int c=0):row(a),col(b),lwh(x),len(c){};
	int row;
	int col;
	int lwh;
	int len;
};

Cell start;
Cell end;
queue<Cell> path;
int C,R,L;
bool view[33][33][33];
int offset[6][3]={{-1,0,0},{0,1,0},{1,0,0},{0,-1,0},{0,0,1},{0,0,-1}};

int bfs(){
	int x = path.front().row;
	int y = path.front().col;
	int z = path.front().lwh;
	int l = path.front().len;
	path.pop();
	if(x==end.row && y==end.col && z==end.lwh){
		while(!path.empty()) path.pop();
		return l;
	}
	else{
		for(int i=0;i<6;++i){
			int new_x = x+offset[i][0];
			int new_y = y+offset[i][1];
			int new_z = z+offset[i][2];
			if(new_x>=0 && new_x<R && new_y>=0 && new_y<C && new_z>=0 && new_z<L && !view[new_x][new_y][new_z]){
				Cell ce(new_x,new_y,new_z,l+1);
				view[new_x][new_y][new_z]=true;
				path.push(ce);
			}
		}
	}
	return -1;
}
int main(){
	//freopen("data.txt","r",stdin);
	while(scanf("%d %d %d",&L,&R,&C) && !(R==0 && C==0 && L==0) ){
		getchar();
		memset(view,true,sizeof(view));
		int depth(0);
		char ch;
		char tmp[33];
		for(int z=0;z<L;++z){
			for(int x=0;x<R;++x){
				for(int y=0;y<C;++y){
					scanf("%c",&ch);
					if(ch=='#') continue;
					view[x][y][z]=false;
					if(ch=='S'){
						start.row=x;	start.col=y;		start.lwh=z;
					}else if(ch=='E'){
						end.row=x;		end.col=y;		    end.lwh=z;
					}
				}
				getchar();
			}
			getchar();
		}
		path.push(start);
		view[start.row][start.row][start.lwh]=true;
		while(!path.empty()){
			depth = bfs();
			if(path.empty()) break;
		}
		if(depth==-1) printf("Trapped!\n");
		else printf("Escaped in %d minute(s).\n",depth);
	}
	return 0;
}