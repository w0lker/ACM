//…Ò≈£Ω‚∑®£∫ www.matrix67.com/blog/archives/266
//www.cnblogs.com/lichen782/p/leetcode_NQueenII.html

#include<vector>
#include<string>
using namespace std;

class Solution {
	int *column;
	int N;
	int CNT;
	bool check(int row){
		for(int i=0;i<row;++i){
			if(column[row]==column[i] || row-column[row]==i-column[i] || row+column[row]==i+column[i]) return false;
		}
		return true;
	}
	void dfs(int row){
		if(row==N) {
			++CNT;
			return;
		}
		for(int col=0;col<N;++col){
			column[row] = col;
			if(!check(row)) continue;
			dfs(row+1);
		}
		column[row] = -1;
	}
public:
    int totalNQueens(int n) {
        N = n;
		CNT = 0;
		column = new int[N];
		memset(column,-1,sizeof(bool)*N);
		dfs(0);
		delete [] column;
		return CNT;
    }
};