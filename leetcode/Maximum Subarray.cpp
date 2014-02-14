#include <algorithm>
using namespace std;
class Solution {
public:
    int maxSubArray(int A[], int n) {
	    int ans = INT_MIN;
	    int tmp = 0;
	    for(int i=0;i<n;++i){
	        tmp += A[i];
	        ans = max(ans,tmp);
	        if(tmp<0)  tmp = 0;
	    }
	    return ans;
    }
};