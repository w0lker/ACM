#include<vector>
#include<set>
#include<iostream>
using namespace std;

class Solution {
	//int get_mat(int i,int j){
	//	// return mat index 1~9
	//	//if(i>=1 && i<=3 && j>=1 &&j<=3) return 1;
	//}
	bool valid(int ro,int co,vector<vector<char> > &board){		//i: col j: row
		int num = board[ro-1][co-1]-'0';
		cout<<(col[co].count(num)+row[ro].count(num)+mat[dict[ro][co]].count(num) == 0)<<endl;
		return col[co].count(num)+row[ro].count(num)+mat[dict[ro][co]].count(num) == 0;
	}
	vector< set<int> > row;
	vector< set<int> > col;
	vector< set<int> > mat;
	int dict[10][10];
	bool DFS(int ro,int co,vector<vector<char> > &board){	//i: col j: row
		if(ro>9) return true;
		if(board[ro-1][co-1]!='.') return DFS((co==9)?(ro+1):ro,(co+1)%9,board);	// valid(i,j,board) && 没做边界处理
		for(int k=1;k<=9;++k){
			board[ro-1][co-1] = k+'0';
			if(valid(ro,co,board)){
				col[co].insert(k);
				row[ro].insert(k);
				mat[dict[ro][co]].insert(k);
				if((DFS((co==9)?(ro+1):ro,(co+1)%10,board))) return true;
				col[co].erase(k);
				row[ro].erase(k);
				mat[dict[ro][co]].erase(k);	
			}
		}
		board[ro-1][co-1] = '.';
		return false;
	}
public:
    void solveSudoku(vector<vector<char> > &board) {
		memset(dict,0,sizeof(dict));
		for(int i=1;i<=9;++i)
			for(int j=1;j<=9;++j){
				if(i<=3){
					if(j<=3) dict[i][j] = 1;
					else if(j<=6) dict[i][j] = 2;
					else dict[i][j] = 3;
				}else if(i<=6){
					if(j<=3) dict[i][j] = 4;
					else if(j<=6) dict[i][j] = 5;
					else dict[i][j] = 6;
				}else{
					if(j<=3) dict[i][j] = 7;
					else if(j<=6) dict[i][j] = 8;
					else dict[i][j] = 9;
				}
			}
        for(int i=0;i<10;++i){
				set<int> s;
				row.push_back(s);
				col.push_back(s);
				mat.push_back(s);
		}
		for(int i=1;i<=9;++i){
			for(int j=1;j<=9;++j){
				if(board[i-1][j-1]!='.'){
					int d = board[i-1][j-1] - '0' + 0;
					row[i].insert(d);
					col[j].insert(d);
					mat[dict[i][j]].insert(d);
				}
			}
		}
		DFS(1,1,board);
    }
};

/**
Solution sol;
	vector< vector<char> > board;
	char c1[9] = {'5','3','.','.','7','.','.','.','.'};
	char c2[9] = {'6','.','.','1','9','5','.','.','.'};
	char c3[9] = {'.','9','8','.','.','.','.','6','.'};
	char c4[9] = {'8','.','.','.','6','.','.','.','3'};
	char c5[9] = {'4','.','.','8','.','3','.','.','1'};
	char c6[9] = {'7','.','.','.','2','.','.','.','6'};
	char c7[9] = {'.','6','.','.','.','.','2','8','.'};
	char c8[9] = {'.','.','.','4','1','9','.','.','5'};
	char c9[9] = {'.','.','.','.','8','.','.','7','9'};
	//for(int i=1;i<=9;++i){}
	vector<char> vec(c1,c1+9); board.push_back(vec);
	vector<char> vec2(c2,c2+9); board.push_back(vec2);
	vector<char> vec3(c3,c3+9); board.push_back(vec3);
	vector<char> vec4(c4,c4+9); board.push_back(vec4);
	vector<char> vec5(c5,c5+9); board.push_back(vec5);
	vector<char> vec6(c6,c6+9); board.push_back(vec6);
	vector<char> vec7(c7,c7+9); board.push_back(vec7);
	vector<char> vec8(c8,c8+9); board.push_back(vec8);
	vector<char> vec9(c9,c9+9); board.push_back(vec9);
	sol.solveSudoku(board);
**/