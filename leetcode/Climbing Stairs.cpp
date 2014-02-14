/////////////////////////////////////////////////////////////////////////////////////////////
#include<vector>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
		if(n==0) return 0;
		else if(n==1) return 1;
		else if(n==2) return 2;
        vector<int> ans(3,0);
		ans[0] = 1;
		ans[1] = 2;
		for(int i=3;i<=n;++i){
			int a=i%3,b=(i+1)%3,c=(i-1)%3;
			ans[c] = ans[b] + ans[a];
		}
		return ans[(n-1)%3];
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<vector>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
		if(n==0) return 0;
		else if(n==1) return 1;
		else if(n==2) return 2;
        vector<int> ans(n+1,0);
		ans[1] = 1;
		ans[2] = 2;
		for(int i=3;i<=n;++i){
			ans[i] = ans[i-1] + ans[i-2];
		}
		return ans[n];
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
    int dp[100000];
    Solution(){
        memset(dp,0,sizeof(dp));
    }
public:
    int climbStairs(int n) {
        if(n==0) return 0;
        else if(n==1) return 1;
        else if(n==2) return 2;
        else{
            if(!dp[n]) dp[n] = climbStairs(n-1)+ climbStairs(n-2);
            return dp[n];
        }
    }
};