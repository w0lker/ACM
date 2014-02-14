/**
uvaoj 673	Parentheses Balance ˮ��һ����
**/
#include <iostream>
#include <stack>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::string;

int n;

inline bool isleft(char c){
	return (c=='(' || c=='[' );
}
inline bool match(char c1,char c2){
	return (c1=='(' && c2==')')||(c1=='[' && c2==']');
}

int main(){
	cin>>n; 
	cin.get();				
	while(n--){
		stack<char> stk;
		bool rst(true);
		string str;
		getline(cin,str);

		for(int i=0;i<str.size();i++){
			if(isleft(str[i]))		//�������( ���� [
				stk.push(str[i]);
			else{					//������� ) ���� ]
				if(stk.size()==0 || !match(stk.top(),str[i])) {
					rst=false; 
					break;
				}
				stk.pop();
			}
		}
		if(stk.size()) rst=false;
		cout<<(rst?"Yes":"No")<<endl;
	}

	return 0;
}