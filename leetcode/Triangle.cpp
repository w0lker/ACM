#include <algorithm>
//当前值的最小路径和为其左上方、右上方路径和的较小值加上当前点的值。
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
		if(triangle.empty() || triangle[0].empty()) return 0;
        int n = triangle.size();
		if(n==1) return *(min_element(triangle[0].begin(),triangle[0].end()));
		vector<int> dp(2*n-1,0);
		dp[int(n-0.5)] = triangle[0][0];
		int ans = INT_MAX;
		for(int i=1;i<n;++i){
			int m = triangle[i].size();
			int base = n - 1 - i;
			for(int j=0;j<m;++j){
				int a = INT_MAX,b=INT_MAX;
				int index = 2*j + base;
				if(j>0) a = dp[index-1];
				if(j<m-1) b = dp[index+1];
				dp[index] = triangle[i][j]+min(a,b);
				if(i==n-1){
					ans = min(ans,dp[index]);
				}
			}
		}
		return ans;
    }
};

//测试数据
//vector<int> v1;v1.push_back(2);
//	  vector<int> v2;v2.push_back(3);v2.push_back(4);
//	  vector<int> v3;v3.push_back(6);v3.push_back(5);v3.push_back(7);
//	  vector<int> v4;v4.push_back(4);v4.push_back(1);v4.push_back(8);v4.push_back(3);
//	  vector< vector<int> > vec;
//	  vec.push_back(v1); //vec.push_back(v2);//vec.push_back(v3); vec.push_back(v4);