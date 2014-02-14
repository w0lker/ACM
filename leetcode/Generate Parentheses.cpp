//也可以用迭代式： 
//blog.unieagle.net/2012/09/21/leetcode%E9%A2%98%E7%9B%AE%EF%BC%9Agenerate-parentheses/
//discuss.leetcode.com/questions/203/generate-parentheses

//DFS当剩余右括号大于左括号时可以push(或)，否则只能push(
//当left==0时直接把剩余的)全部push进去
#include<vector>
#include<string>
using namespace std;

class Solution {
	vector<string> ans;
	void DFS(string pre,int left,int right){
		if(left==0){
			for(int i=0;i<right;++i)
				pre.push_back(')');
			ans.push_back(pre);
			return;
		}
		DFS(pre+'(',left-1,right);
		if(right>left) DFS(pre+')',left,right-1);
	}
public:
    vector<string> generateParenthesis(int n) {
		DFS("",n,n);
		return ans;
    }
};
