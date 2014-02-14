
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size(); if(n==0) return;
        for(int r=0;r<n/2;++r){
            for(int c=r;c<n-(r+1);++c){//注意c不是以0开始计算的！！
                int t = matrix[r][c];
				matrix[r][c] = matrix[n-(c+1)][r];
				matrix[n-(c+1)][r] = matrix[n-(r+1)][n-(c+1)];
				matrix[n-(r+1)][n-(c+1)] = matrix[c][n-(r+1)];
				matrix[c][n-(r+1)] = t;
            }
        }
    }
};