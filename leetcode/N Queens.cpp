//迭代算法
//1、zhedahht.blog.163.com/blog/static/2541117420114331616329/
//2、blog.unieagle.net/2012/10/16/leetcode%E9%A2%98%E7%9B%AE%EF%BC%9An-queens%EF%BC%8C%E5%9B%9E%E6%BA%AF/ 



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//解法2 用一个column数组保存row行Q所在列即可，不需传送整个vector
#include<vector>
#include<string>
using namespace std;

class Solution {
	int N;
	vector<int> vis1,vis2,vis3;
	vector<int> column;
	vector<vector<string> > board;
	void dfs(int row){
		if(row==N){
			vector<string> vec;
			for(int i=0;i<N;++i){
				string line(N,'.');
				line[column[i]] = 'Q';
				vec.push_back(line);
			}
			board.push_back(vec);
			return;
		}
		bool isOk = false;
		for(int col=0;col<N;++col){
			if(vis1[col] || vis2[col-row+N-1] || vis3[col+row]) continue;
			vis1[col] = vis2[col-row+N-1] = vis3[col+row] = true;
			column[row] = col;
			dfs(row+1);
			vis1[col] = vis2[col-row+N-1] = vis3[col+row] = false;
			//column[row] = 0;
		}
	}
public:
    vector<vector<string> > solveNQueens(int n) {
        N = n;
		vis1.assign(N,0);
		vis2.assign(2*N-1,0);
		vis3.assign(2*N-1,0);
		vector<string> vec;
		column.assign(N,0);
		dfs(0);
		return board;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//解法1，有个问题传递方式为值传递。。。
#include<vector>
#include<string>
using namespace std;

class Solution {
	int N;
	vector<int> vis1,vis2,vis3;
	vector<vector<string> > board;
	bool dfs(int row,vector<string> vec){
		if(row>=N){
			board.push_back(vec);
			return true;
		}
		bool isOk = false;
		for(int col=0;col<N;++col){
			if(vis1[col] || vis2[col-row+N-1] || vis3[col+row]) continue;
			vec[row][col] = 'Q';
			vis1[col] = vis2[col-row+N-1] = vis3[col+row] = true;
			if(dfs(row+1,vec)){
				isOk = true;
			}
			vec[row][col] = '.';
			vis1[col] = vis2[col-row+N-1] = vis3[col+row] = false;
		}
		return isOk;
	}

public:
    vector<vector<string> > solveNQueens(int n) {
        N = n;
		vis1.assign(N,0);
		vis2.assign(2*N-1,0);
		vis3.assign(2*N-1,0);
		vector<string> vec;
		for(int i=0;i<N;++i){
			vec.push_back(string(N,'.'));
		}
		dfs(0,vec);
		return board;
    }
};