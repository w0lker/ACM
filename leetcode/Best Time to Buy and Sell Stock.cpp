#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
		if(n<=1) return 0;
		int *dp = new int[n];
		int ans = dp[0] = 0;
		int minPrice = prices[0];
		for(int i=1;i<n;++i){
			dp[i] = max(dp[i-1],prices[i]-minPrice);
			if(prices[i]<minPrice) minPrice = prices[i];
			if(dp[i]>ans) ans = dp[i];
		}
		return ans;
    }
};