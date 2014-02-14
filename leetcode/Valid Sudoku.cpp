//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//�ⷨ2��ֱ����һ�������ʾÿ�С�ÿ�С�ÿ���Ź����Ƿ��Ѿ���1~9�е�ĳ������ռ����
//www.cnblogs.com/zhaolizhen/p/Sudoku.html

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//�ⷨ1
//�޴������row col��Ӧ�ķ�����Ŵ���13�У���ʵֻ��Ҫһ�д��뼴�ɣ�i-i%3+j/3   

#include<vector>
#include<set>
#include<cstring>
using namespace std;
class Solution {
		int get_mat(int row,int col){
			return row - row%3 + col/3;
		}
		/*int get_mat(int row,int col){
			switch(row){
				case 0: case 1: case 2:
					switch(col){
						case 0: case 1: case 2: return 0;
						case 3: case 4: case 5: return 1;
						case 6: case 7: case 8: return 2;
					};
					break;
				case 3: case 4: case 5:
					switch(col){
						case 0: case 1: case 2: return 3;
						case 3: case 4: case 5: return 4;
						case 6: case 7: case 8: return 5;
					};
					break;
				default:
					switch(col){
						case 0: case 1: case 2: return 6;
						case 3: case 4: case 5: return 7;
						case 6: case 7: case 8: return 8;
					};
					break;
			}
		}*/
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        set<int> rows[9],cols[9],mats[9];
        for(int r=0;r<9;++r){
            for(int c=0;c<9;++c){
                char ch = board[r][c];
                if(ch!='.'){
                    int m = get_mat(r,c);
                    if(rows[r].find(ch)!=rows[r].end() || cols[c].find(ch)!=cols[c].end() 
                       || mats[m].find(ch)!=mats[m].end())  return false;
                    rows[r].insert(ch);
                    cols[c].insert(ch);
                    mats[m].insert(ch);
                }
            }
        }
        return true;
    }
};