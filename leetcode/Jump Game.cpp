//ֱ�Ӷ�̬�滮�����Իᳬʱ
#include <cstring>

class Solution {
private:
	int *arr,N;
	short *dp;
	short dfs(int pos){
		if(pos>=N-1) return 1;
		if(dp[pos]!=-1) return dp[pos];
		for(int i=arr[pos];i>=1;--i){
			if(dfs(pos+i)) return dp[pos] = 1;
		}
		return dp[pos] = 0;
	}
public:
    bool canJump(int A[], int n) {
		if(n<=1) return true;
        arr = A;
		N = n;
		dp = new short[N];
		memset(dp,-1,sizeof(short)*N);
		bool ans = dfs(0);
		delete [] dp;
		return ans;
    }
};

//̰��  ����pass
//���� ��������Զ�������һ��
#include <algorithm>
using namespace std;

class Solution {
	bool canJump(int A[],int pos,int n){
		if(pos>=n-1) return true;
		int maxPos = pos;
		for(int i=1;i<=A[pos];++i){
			maxPos = max(maxPos,pos+i+A[pos+i]);			
		}
		if(maxPos==pos) return false;
		return canJump(A,maxPos,n);
	}
public:
    bool canJump(int A[], int n) {
		if(n<=1) return true;
        return canJump(A,0,n);
    }
};

//��ţ�Ľⷨ��û����
//blog.csdn.net/kenden23/article/details/17242835