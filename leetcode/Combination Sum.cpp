//DFS
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
	vector< vector<int> > ans;
	void dfs(int index,int sum,int target,vector<int> &candidates,vector<int> &path){
		if(sum>target) return;
		if(sum==target){
			ans.push_back(path);
			return;
		}
		for(int i=index;i<candidates.size();++i){
			path.push_back(candidates.at(i));
			dfs(i,sum+candidates.at(i),target,candidates,path);
			path.pop_back();
		}
	}
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		sort(candidates.begin(),candidates.end());
		if(candidates.empty()) return ans;
		vector<int> path;
		dfs(0,0,target,candidates,path);
		return ans;
    }
};