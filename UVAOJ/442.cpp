/**
	uvaoj_442 矩阵相乘次数计算
	错误的代码示例：http://blog.csdn.net/u011262722/article/details/11859317 
	不能正确处理(ABC)的情况，但是uvaoj居然AC了。。。
	正确代码参考： http://blog.csdn.net/synapse7/article/details/9714085
**/
#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::string;

struct matrix{
	int row;
	int col;
};

matrix mtx[30];
int n;

int main(){
	cin>>n;
	cin.get();
	while(n--){
		char c;
		matrix m;
		cin>>c>>m.row>>m.col;
		mtx[c-'A']=m;
	}
	cin.get();
	string line;
	while(getline(cin,line)){
		stack<char> sc;
		stack<matrix> sm;
		int ans(0);
		bool flag(true);
		for(int i=0;i!=line.size();++i){
			//cout<<line[i]<<endl;
			if(line[i]=='(') 
				sc.push(line[i]);		//左括号直接入栈
			else if(isalpha(line[i])){				//矩阵
				if(sc.size()==0 || sc.top()!='#'){					//sc栈顶没有#，表示没有矩阵和当前矩阵直接相连。矩阵入栈，
					sm.push(mtx[line[i]-'A']);
					sc.push('#');
				}else{								//sc栈顶有#,需要将当前矩阵和sm栈栈顶的矩阵相乘
					if(sm.top().col!=mtx[line[i]-'A'].row){
						flag=false;
						break;
					}
					ans+=(sm.top().row*sm.top().col*mtx[line[i]-'A'].col);
					matrix tmp;
					tmp.row=sm.top().row;
					tmp.col=mtx[line[i]-'A'].col;
					sm.pop();
					sm.push(tmp);
				}
			}else{									//右括号
				if(line[i]!=')') cout<<"怎么可能"<<endl;
				sc.pop();
				sc.pop();
				while(sc.size()>0 && sc.top()=='#'){
					matrix tmp;
					tmp.col=sm.top().col;
					tmp.row=sm.top().row;
					sm.pop();
					if(sm.top().col!=tmp.row){
						flag=false;
						break;
					}
					ans+=(sm.top().row*sm.top().col*tmp.col);
					tmp.row=sm.top().row;
					sc.pop();
					sm.pop();
					sm.push(tmp);
				}
				sc.push('#');
			}
		}
		if(flag)  cout<<"anser: "<<ans<<endl;
		else	  cout<<"error"<<endl;
	}
	return 0;
}