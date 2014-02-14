//方法1：百度百科： 递归生成码表
//
//这种方法基于格雷码是反射码的事实，利用递归的如下规则来构造：
//1位格雷码有两个码字
//(n+1)位格雷码中的前2n个码字等于n位格雷码的码字，按顺序书写，加前缀0
//(n+1)位格雷码中的后2n个码字等于n位格雷码的码字，按逆序书写，加前缀1


//方法2： 直接生产格雷码
//
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
		int max = 1<<n;
        for(int i=0;i<max;++i){
			ans.push_back(i^(i>>1));
        }
		return ans;
    }
};