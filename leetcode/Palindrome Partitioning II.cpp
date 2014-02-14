//直接套用palindrome partition会超时：
class Solution {
	bool dp[555][555];
	int ans;
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
	void dfs(int index,int cnt,const string &str){
		if(index==str.size()){
			ans = min(ans,cnt-1);
			return;
		}
		for(int i=index;i<str.size();++i){
			if(isPalindrome(str,index,i)){
				dfs(i+1,cnt+1,str);
			}
		}
	}
public:
	int minCut(string s) {
        if(s.empty()) return 0;
		memset(dp,false,sizeof(bool)*555*555);
		ans = INT_MAX;
		dfs(0,0,s);
		return ans;
    }
};