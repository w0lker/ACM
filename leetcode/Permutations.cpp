
class Solution {
    vector<vector<int> > ans;
    int N;
    void dfs(vector<int> &path,vector<int> &num){
        if(path.size()==N){
            ans.push_back(path);
            return;
        }
        for(int i=0;i<N;++i){
            if(find(path.begin(),path.end(),num[i])==path.end()){
                path.push_back(num[i]);
                dfs(path,num);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int> > permute(vector<int> &num) {
        N = num.size();
        if(N==0) return ans;
        vector<int> vec;
        dfs(vec,num);
		return ans;
    }
};