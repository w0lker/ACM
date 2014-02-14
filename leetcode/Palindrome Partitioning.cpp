//解法2 加上动态规划
class Solution {
	bool dp[555][555];
	vector<vector<string>> ans;
	bool isPalindrome(const string &str,int start,int end){
		if(dp[start][end]) return true;
		if(start==end) return true;
		int i=start,j=end;
		while(i<j){
			if(str[i]!=str[j]) return false;
			++i;
			--j;
		}
		return dp[start][end] = true;
	}
	void dfs(int index,const string &str,vector<string> &path){
		if(index==str.size()){
			ans.push_back(path);
			return;
		}
		for(int i=index;i<str.size();++i){
			if(isPalindrome(str,index,i)){
				path.push_back(str.substr(index,i-index+1));
				dfs(i+1,str,path);
				path.pop_back();
			}
		}
	}
public:
    vector<vector<string>> partition(string s) {
		if(s.empty()) return ans;
        vector<string> path;
		memset(dp,false,sizeof(bool)*555*555);
		dfs(0,s,path);
		return ans;
    }
};
//解法1 暴力搜索
class Solution {
	vector<vector<string>> ans;
	bool isPalindrome(const string &str,int start,int end){
		if(start==end) return true;
		int i=start,j=end;
		while(i<j){
			if(str[i]!=str[j]) return false;
			++i;
			--j;
		}
		return true;
	}
	void dfs(int index,const string &str,vector<string> &path){
		if(index==str.size()){
			ans.push_back(path);
			return;
		}
		for(int i=index;i<str.size();++i){
			if(isPalindrome(str,index,i)){
				path.push_back(str.substr(index,i-index+1));
				dfs(i+1,str,path);
				path.pop_back();
			}
		}
	}
public:
    vector<vector<string>> partition(string s) {
		if(s.empty()) return ans;
        vector<string> path;
		dfs(0,s,path);
		return ans;
    }
};