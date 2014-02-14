/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//�ⷨ1����Ľ�������� �������µ�����������ͨ����board�е�O�滻��#����ʾ��ΧO��
//������һ��ѭ������#�滻��X,#�滻��O

//�������������ݹ��ηǳ��������dfs�����滻��ע���еĴ��붼�������ջ���

/**
						'X', 'X','X' ,'O',
						'X' ,'O', 'X', 'O',
						'X', 'X', 'X', 'X',
						'O' ,'O', 'O', 'O',
						'X', 'X','X' ,'O',
						'X' ,'O', 'O', 'X',
						'O', 'X', 'X', 'X',
						'O' ,'O', 'O', 'O',
						'X', 'X','X' ,'O',
**/
//		static int offset[4][2] = {-1,0,0,1,1,0,0,-1};

//		if(board[row][col]=='O'){
//			board[row][col] = '#';	//��ʾ�Ѿ����ʹ�δ����Χ�ġ�O'
//			int n_row,n_col;
//			for(int i=0;i<4;++i){
//				n_row = row + offset[i][0];
//				n_col = col + offset[i][1];
//				dfs(n_row,n_col,board);
//			 }
//		}

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    int R_NUM,C_NUM;
    void dfs(int row,int col,vector<vector<char>> &board){
		if(row<0 || row>=R_NUM || col<0 || col>=C_NUM) return;
        if(board[row][col]=='O'){
			board[row][col] = '#';	//��ʾ�Ѿ����ʹ�δ����Χ�ġ�O'
			dfs(row-1,col,board);
			dfs(row,col+1,board);
			dfs(row+1,col,board);
			dfs(row,col-1,board);
		}
		
    }
public:
    void solve(vector<vector<char>> &board) {
        R_NUM = board.size();
		if(R_NUM==0) return;
        C_NUM = board[0].size();
        if(R_NUM<3 || C_NUM<3) return;
        for(int col=0;col<C_NUM;++col){
            dfs(0,col,board);
            dfs(R_NUM-1,col,board);
        }
        for(int row=0;row<R_NUM;++row){
            dfs(row,0,board);
            dfs(row,C_NUM-1,board);
        }
        for(int row=0;row<R_NUM;++row){
			for(int col=0;col<C_NUM;++col){
				board[row][col] = (board[row][col]=='#')?'O':'X';
			}
		}
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//����1�� �����˶����������ά������runtime error�����ǿռ����
#include<vector>
#include<algorithm>
using namespace std;

static int offset[4][2] = {-1,0,0,1,1,0,0,-1};
class Solution {
    vector<vector<char>> myboard;
    vector<vector<int>> vis;
    int R_NUM,C_NUM;
    void dfs(int row,int col,vector<vector<char>> &board){
        //if(vis[row][col]) return;
        myboard[row][col] = 'O';
        vis[row][col] = 1;
        int n_row,n_col;
        for(int i=0;i<4;++i){
            n_row = row + offset[i][0];
            n_col = col + offset[i][1];
            if(n_row<0 || n_row==R_NUM || n_col<0 || n_col==C_NUM) continue;
            if(!vis[n_row][n_col] && board[n_row][n_col]=='O') dfs(n_row,n_col,board);
        }
    }
public:
    void solve(vector<vector<char>> &board) {
        R_NUM = board.size();
        C_NUM = board[0].size();
        if(R_NUM<3 || C_NUM<3) return;
        for(int row=0;row<R_NUM;++row){
            vector<char> vec(C_NUM,'X');
            myboard.push_back(vec);
            vector<int> v(C_NUM,0);
            vis.push_back(v);
        }
        for(int col=0;col<C_NUM;++col){
            if(board[0][col]=='O' && !vis[0][col]) dfs(0,col,board);
            if(board[R_NUM-1][col]=='O' && !vis[R_NUM-1][col]) dfs(R_NUM-1,col,board);
        }
        for(int row=0;row<R_NUM;++row){
            if(board[row][0]=='O' && !vis[row][0]) dfs(row,0,board);
            if(board[row][C_NUM-1]=='O' && !vis[row][C_NUM-1]) dfs(row,C_NUM-1,board);
        }
        swap(board,myboard);
    }
};


//����
//char arr[9][4] = {
//						'X', 'X','X' ,'O',
//						'X' ,'O', 'X', 'O',
//						'X', 'X', 'X', 'X',
//						'O' ,'O', 'O', 'O',
//						'X', 'X','X' ,'O',
//						'X' ,'O', 'O', 'X',
//						'O', 'X', 'X', 'X',
//						'O' ,'O', 'O', 'O',
//						'X', 'X','X' ,'O',
//	};
//	 vector<vector<char>> board;
//	 for(int i=0;i<9;++i)
//		 board.push_back(vector<char>(arr[i],arr[i]+4));