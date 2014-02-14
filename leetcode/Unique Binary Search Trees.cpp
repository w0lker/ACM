#include <cstdlib>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if(n<=2) return n;
		int *dp = (int*)malloc(sizeof(int)*(n+1));
		memset(dp,0,sizeof(int)*(n+1));
		dp[1] = 1;
		dp[2] = 2;
		//��ʵ���Ժϲ�Ϊ��һ���
		//�Ϸ�����0~n-1,�·�����n-1~0
		for(int i=3;i<=n;++i){
			dp[i] += 2*dp[i-1];
			for(int j=1;j<i-1;++j){
				dp[i] += dp[j]*dp[i-1-j];
			}
		}
		//free����
		return dp[n];
    }
};