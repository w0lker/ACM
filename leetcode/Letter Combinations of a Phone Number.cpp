/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//优化：
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
	vector<string> ans;
	int n;
	vector<int> di;		//输入序列转成整形向量
	vector< string > ds;	//每个数字代表的char
	void DFS(string prefix,int i){
		if(n==i){
			ans.push_back(prefix);
			return;
		}
		int d = di[i];
		for(int k=0;k<ds[d].size();++k){
			DFS(prefix+ds[d][k],i+1);
		}
	}
public:
    vector<string> letterCombinations(string digits) {
		string str[10] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		for(int i=0;i<10;++i) ds.push_back(str[i]);
		n = digits.size();
		for(int i=0;i<n;++i){
			di.push_back(0+digits[i]-'0');
		}
		DFS("",0);
		return ans;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//保存map的方法有点愚蠢
#include<vector>
#include<string>
using namespace std;

class Solution {
	vector<string> ans;
	int n;
	vector<int> di;		//输入序列转成整形向量
	vector< vector<char> > ds;	//每个数字代表的char
	void DFS(string prefix,int i){
		if(n==i){
			ans.push_back(prefix);
			return;
		}
		int d = di[i];
		for(int k=0;k<ds[d].size();++k){
			DFS(prefix+ds[d][k],i+1);
		}
	}
	inline int ctoi(char c){
		return 0+c-'0';
	}
public:
    vector<string> letterCombinations(string digits) {
		char a0[1] = {' '};
		ds.push_back(vector<char>(a0,a0+1));
		vector<char> v;
		ds.push_back(v);
		char a2[3] = {'a','b','c'};
		ds.push_back(vector<char>(a2,a2+3));
		char a3[3] = {'d','e','f'};
		ds.push_back(vector<char>(a3,a3+3));
		char a4[3] = {'g','h','i'};
		ds.push_back(vector<char>(a4,a4+3));
		char a5[3] = {'j','k','l'};
		ds.push_back(vector<char>(a5,a5+3));
		char a6[3] = {'m','n','o'};
		ds.push_back(vector<char>(a6,a6+3));
		char a7[4] = {'p','q','r','s'};
		ds.push_back(vector<char>(a7,a7+4));
		char a8[3] = {'t','u','v'};
		ds.push_back(vector<char>(a8,a8+3));
		char a9[4] = {'w','x','y','z'};
		ds.push_back(vector<char>(a9,a9+4));
        n = digits.size();
		for(int i=0;i<n;++i){
			di.push_back(ctoi(digits[i]));
		}
		DFS("",0);
		return ans;
    }
};