//˼·1���򵥵ݹ�,������Ϊn���ַ������ֳ�n�����a,bȻ��ֱ�Ƚ�
//�ݹ��п��Խ�s1,s2�ַ�����ͬ�ļ���
//˼·2��3ά��̬�滮		û��������������������������������������������������
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
		//���ߣ�int ***dp = new int**[len];
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

