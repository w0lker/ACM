//思路1：简单递归,将长度为n的字符串划分成n中组合a,b然后分别比较
//递归中可以将s1,s2字符集不同的减掉
//思路2：3维动态规划		没做出来！！！！！！！！！！！！！！！！！！！！！！
#include<string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
		/*if(s1.size()!=s2.size()) return false;
		if(s1.empty()) return true;*/
		int n = s1.size();
		int ***dp = (int***)malloc(sizeof(int***)*n);
		//或者：int ***dp = new int**[len];
		for(int i=0;i<n;++i){
			dp[i] = (int**)malloc(sizeof(int**)*n);
			for(int j=0;j<n;++j){
				dp[i][j] = (int*)malloc(sizeof(int*)*n);
				memset(dp[i][j],0,sizeof(int)*n);
			}
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				dp[1][i][j] = s1[i]==s2[j]?1:0;
			}
		}
		for(int len=2;len<=n;++len){
			for(int i=0;i<=n-len;++i)
				for(int j=0;j<=n-len;++j)
					for(int k=1;k<len;++k){
						if((dp[k][i][j] && dp[len-k][i+k][j+k])||
							(dp[k][i][j+len-k] && dp[len-k][i+len-k][j]))
						{
							dp[len][i][j] = 1;
							break;
						}
					}
			
		}
		return dp[n][0][0];
    }
};

