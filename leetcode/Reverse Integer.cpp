//������ܻ��������������Χ���������磺 1000000009

//��İ취�������鱣�棬�����㡣
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
//�����Ľⷨ��
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