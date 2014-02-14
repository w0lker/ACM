/**
陷阱：
1、["-1","1","*","-1","+"] 把-1的负号当成减号了
2、只有单个数字时，stack不会被清空，需要单独考虑。
3、string可以直接转成int，用stoi函数，而不用string.c_str()然后再用atoi
**/

#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
	bool is_operator(string &str);
	int operate(int a,int b,char c);
public:
    int evalRPN(vector<string> &tokens) {
		int i = 0,a,b;
		int n = tokens.size();
		if(n==1) return atoi(tokens.at(0).c_str());
		string str;
		stack<int> st;
		while(i<n){
			str = tokens.at(i);
			if(is_operator(str)){
				b = st.top();	st.pop();
				a = st.top();	st.pop();
				st.push(operate(a,b,str.at(0)));
			}else st.push(stoi(str));
			++i;
		}
		return st.top();
    }
};

bool Solution::is_operator(string &str){
	return (str=="+" || str=="-" || str=="*"  || str=="/");
}

int Solution::operate(int a,int b,char c){
	switch (c){
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		case '/':return a/b;
	}
}




//原始版：
//#include <stack>
//#include <vector>
//#include <string>
//using namespace std;
//
//class Solution {
//private:
//	bool is_operator(char c);
//	int operate(int a,int b,char c);
//	int c2i(char c);
//public:
//    int evalRPN(vector<string> &tokens) {
//		int ans = 0,i = 0,a,b;
//		int n = tokens.size();
//		if(n==1) return atoi(tokens.at(0).c_str());
//		string str;
//		stack<int> st;
//		while(i<n){
//			str = tokens.at(i);
//			if(str.size()==1 && is_operator(str.at(0))){
//				b = st.top();	st.pop();
//				a = st.top();	st.pop();
//				st.push(ans = operate(a,b,str.at(0)));
//			}else st.push(atoi(str.c_str()));
//			++i;
//		}
//		return ans;
//    }
//};
//
//bool Solution::is_operator(char c){
//	return (c=='+' || c=='-' || c=='*' || c=='/');
//}
//
//int Solution::operate(int a,int b,char c){
//	switch (c){
//		case '+': return a+b;
//		case '-': return a-b;
//		case '*': return a*b;
//		case '/':return a/b;
//	}
//}


//测试数据：
//vector<string> vec;
//vec.push_back("2");vec.push_back("1");vec.push_back("+");vec.push_back("3");vec.push_back("*");
//vec.push_back("4");vec.push_back("13");vec.push_back("5");vec.push_back("/");vec.push_back("+");
//vec.push_back("18");
//vec.push_back("-1");vec.push_back("-1");vec.push_back("-");
//Solution s;
//cout<<s.evalRPN(vec)<<endl;