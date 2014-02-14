#include<vector>
#include<string>
#include<algorithm>
using namespace std;

static int offset[4][2] = {-1,0,0,1,1,0,0,-1};
class Solution {
    int N;
	int	C_NUM;
	int R_NUM;
    bool ans;
    string word;
    vector<vector<char> > board;
    vector<vector<int> > vis;
    void dfs(int n,int r,int c){
        if(ans) return;
        if(n==N-1){
            ans = true;
            return;
        }
        for(int i=0;i<4;++i){
            int new_r = r + offset[i][0];
            int new_c = c + offset[i][1];
            if(!vis[new_r][new_c] && board[new_r][new_c]==word[n+1]){
                vis[new_r][new_c] = 1;
                dfs(n+1,new_r,new_c);
                vis[new_r][new_c] = 0;
            }
        }
    }
public:
    bool exist(vector<vector<char> > &board, string word) {
		if(board.empty() || board[0].empty()) return word.empty();
        ans = false;
        this->word = word;
        N = word.size();
		if(N==0) return true;
		R_NUM = board.size();
		C_NUM = board[0].size();
        vector<char> dumpy(C_NUM+2,'0');
        this->board.push_back(dumpy);
        for(int i=0;i<R_NUM;++i){
            vector<char> vec(C_NUM+2,'0');
            copy(board[i].begin(),board[i].end(),vec.begin()+1);
            this->board.push_back(vec);
        }
        this->board.push_back(dumpy);
		for(int r=0;r<R_NUM+2;++r){
			vector<int> vec(C_NUM+2,0);
			vis.push_back(vec);
		}
        for(int r=1;r<=R_NUM;++r){
            for(int c=1;c<=C_NUM;++c){
               if(!ans && this->board[r][c]==word[0]){
				   vis[r][c] = 1;
				   dfs(0,r,c);
				   vis[r][c] = 0;
			   }
            }
        }
        return ans;
    }
};