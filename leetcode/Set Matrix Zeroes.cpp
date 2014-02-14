#include<vector>
using namespace std;

//�ܽᣨ�����
//�����ռ�Ļ�����һ���Կ����ǲ��ǹ̶������ļ��������ܸ㶨
//	������Կ����ǲ������Ȿ���Ѿ��ṩ���㹻�Ŀռ䡣
//���⣺ �������У����б�����Ϣ
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row = matrix.size();
        if(0==row) return;
        int col = matrix[0].size();
        if(col==0) return;
        //ȷ�����С������Ƿ���Ҫ���㡣
		bool br = false,bc = false;
		for(int i=0;i<col && !br;++i)  if(0==matrix[0][i]){br = true;}
		for(int i=0;i<row && !bc;++i)  if(0==matrix[i][0]){bc = true;}
		//�жϸ��С����Ƿ���Ҫ���㣬���������С�����
		for(int r=1;r<row;++r){
			for(int c=1;c<col;++c){
				if(0==matrix[r][c]){
					matrix[0][c]=0;
					matrix[r][0]=0;
				}
			}
		}
		//����
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

//����ⷨ �������滻������滻�������Ľ����ֻҪ��һ��0�������󶼱��0
//��Ҫ��ԭʼ��0elements���ȱ���������
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