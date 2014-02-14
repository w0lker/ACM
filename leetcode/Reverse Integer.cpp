//逆序可能会输出大于整数范围的数，例如： 1000000009

//最笨的办法：用数组保存，并计算。
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
		bool neg = x<0;
		if(neg) x = -x;
		int arr[33];
		int i = 0;
		for(;i<33 && x!=0 ;++i){
			int a = x%10;
			x /= 10;
			arr[i] = a;
		}
		int j = 0;
		while(arr[j]==0 && j<i) ++j;
		int len = i - j;
		int ans = 0;
		for(int k=j;k<i;++k){
			ans += arr[k]*(int(pow(10.0,i-k-1)));
		}
        if(neg) ans = -ans;
		return ans;
    }
};

////////////////////////////////////////////////////////////////////////////
//超简洁的解法：
class Solution {
public:
    int reverse(int x) {
		int res = 0;
		while(x!=0){
			res = res*10 + x%10;
			x /= 10;
		}
		return res;
	}
};