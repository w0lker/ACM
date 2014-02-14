#include<vector>
using namespace std;

class Solution {
    int N,K;
    vector<vector<int> > ans;
    void dfs(int start,int level,vector<int> &path){
        if(level==K){
            ans.push_back(path);
            return;
        }
        for(int i=start;i<=N;++i){
            path.push_back(i);
            dfs(i+1,level+1,path);
            path.pop_back();
        }
    }
public:
    vector<vector<int> > combine(int n, int k) {
        N = n,K = k;
		vector<int> vec;
		if(n==0 || k==0) return ans;
        dfs(1,0,vec);
        return ans;
    }
};