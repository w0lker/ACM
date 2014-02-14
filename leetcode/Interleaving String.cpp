//二维 DP
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
		if(s1.empty()) return s2==s3;
		if(s2.empty()) return s1==s3;
		int m = s1.size();
		int n = s2.size();
		if((m+n)!=s3.size()) return false;
		int **dp = (int**)malloc((m+1)*sizeof(int*));
		for(int i=0;i<=m;++i){
			dp[i] = (int*)(malloc((n+1)*sizeof(int)));
			memset(dp[i],0,(n+1)*sizeof(int));
		}
		dp[0][0] = true;
		for(int i=0;i<=m;++i){
			for(int j=0;j<=n;++j){
				if(i==0 && j==0) continue;
				if(i==0){
					dp[i][j] = (dp[i][j-1] && s2[j-1]==s3[j-1]);
					continue;
				}
				if(j==0){
					dp[i][j] = (dp[i-1][j] && s1[i-1]==s3[i-1]);
					continue;
				}
				bool b1 = (s3[i+j-1]==s1[i-1] &&(dp[i-1][j]));
				bool b2 = (s3[i+j-1]==s2[j-1] &&(dp[i][j-1]));
				dp[i][j] = (b1||b2);
			}
		}
		//free memory
		return dp[m][n];
    }
};


//  剪枝后的递归方法：
//  blog.unieagle.net/2012/09/29/leetcode%e9%a2%98%e7%9b%ae%ef%bc%9ainterleaving-string%ef%bc%8c%e4%ba%8c%e7%bb%b4%e5%8a%a8%e6%80%81%e8%a7%84%e5%88%92/