//动态规划 注意边界条件
#include<cstring>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
		int N = S.size(),M = T.size();
		if(N==0 || M==0) return 0;
		vector< vector<int> > dp;
		vector<int> v(N,1);
		dp.push_back(v);
		for(int i=1;i<=M;++i){
			vector<int> vec;
			for(int j=0;j<=N;++j) vec.push_back(0);
			dp.push_back(vec);
		}
		dp[0][0] = 1;
		for(int i=1;i<=M;++i)
			for(int j=1;j<=N;++j){
				dp[i][j] = dp[i][j-1];
				if(T[i-1]==S[j-1]) dp[i][j] += dp[i-1][j-1];
			}
		return dp[M][N];
    }
};

//递归 清晰的思路
#include<string>
using namespace std;

class Solution {
	string str;
	string subStr;
	int N,M;
	int dfs(int i,int j){
		if(j==M) return 1;
		if(i==N) return 0;
		int cnt = 0;
		for(int k=i;k<N;++k){
			if(str[k]==subStr[j]) 
				cnt += dfs(k+1,j+1);
		}
		return cnt;
	}
public:
    int numDistinct(string S, string T) {
        str = S;
		subStr = T;
		N = str.size();
		M = subStr.size();
		return dfs(0,0);
    }
};

//递归解法 思路很混乱
//思路混乱的原因,情况分的过细，其实可以统一到更加泛化的边界。
#include<string>
using namespace std;

class Solution {
	string str;
	string subStr;
	int N,M,ans;
	void dfs(int i,int j){
		if(i>=N || (N-i<M-j)) return;
		else if(j==M-1){
			if(str[i]==subStr[j]) ++ans;
		}else{
			while(str[i]!=subStr[j] && i<N) ++i;
			for(int k=i+1;k<=N-M+j;++k){
				dfs(k,j+1);
			}
		}
	}
public:
    int numDistinct(string S, string T) {
        str = S;
		subStr = T;
		N = str.size();
		M = subStr.size();
		ans = 0;
		dfs(0,0);
		return ans;
    }
};