#include<vector>
using namespace std;

//总结（★★★）：
//常数空间的话，第一可以考虑是不是固定数量的几个变量能搞定
//	否则可以考虑是不是问题本身已经提供了足够的空间。
//正解： 利用首行，首列保存信息
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row = matrix.size();
        if(0==row) return;
        int col = matrix[0].size();
        if(col==0) return;
        //确定首行、首列是否需要清零。
		bool br = false,bc = false;
		for(int i=0;i<col && !br;++i)  if(0==matrix[0][i]){br = true;}
		for(int i=0;i<row && !bc;++i)  if(0==matrix[i][0]){bc = true;}
		//判断各行、列是否需要清零，保存在首行、列中
		for(int r=1;r<row;++r){
			for(int c=1;c<col;++c){
				if(0==matrix[r][c]){
					matrix[0][c]=0;
					matrix[r][0]=0;
				}
			}
		}
		//清零
		for(int r=1;r<row;++r) 
			if(matrix[r][0]==0){
				for(int c=1;c<col;++c) matrix[r][c]=0;
			}
		for(int c=1;c<col;++c)
			if(0==matrix[0][c]){
				for(int r=1;r<row;++r) matrix[r][c]=0;
			}
		if(br) for(int c=0;c<col;++c) matrix[0][c]=0;
		if(bc) for(int r=0;r<row;++r) matrix[r][0]=0;
    }
};

//错误解法 把行列替换后继续替换，这样的结果是只要有一个0整个矩阵都变成0
//需要把原始的0elements事先保存起来。
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row = matrix.size();
        if(0==row) return;
        int col = matrix[0].size();
        if(col==0) return;
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(matrix[i][j]==0){
                    for(int k=0;k<col;++k) 
						matrix[i][k]=0;
                    for(int k=0;k<row;++k) 
						matrix[k][j]=0;
                }
            }
        }
    }
};