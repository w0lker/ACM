/**
	uvaoj_442 ������˴�������
	����Ĵ���ʾ����http://blog.csdn.net/u011262722/article/details/11859317 
	������ȷ����(ABC)�����������uvaoj��ȻAC�ˡ�����
	��ȷ����ο��� http://blog.csdn.net/synapse7/article/details/9714085
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
				sc.push(line[i]);		//������ֱ����ջ
			else if(isalpha(line[i])){				//����
				if(sc.size()==0 || sc.top()!='#'){					//scջ��û��#����ʾû�о���͵�ǰ����ֱ��������������ջ��
					sm.push(mtx[line[i]-'A']);
					sc.push('#');
				}else{								//scջ����#,��Ҫ����ǰ�����smջջ���ľ������
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
			}else{									//������
				if(line[i]!=')') cout<<"��ô����"<<endl;
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