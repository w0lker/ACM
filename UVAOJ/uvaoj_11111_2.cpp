/**
����stackһ���������ޣ���һ������������ڲ���������֮��
�߼��ϳ���Ӧ��û�������Լ�������ʮ����Ҳ����ȷ������uvaoj����
���� runtime error ����֪��Ϊʲô��
**/
#include<iostream>
#include<sstream>
#include<string>
#include<stack>
#include<cstdio>
using namespace std;

int main_11111_2()
{
    string line;
    while(getline(cin,line))
    {
        istringstream sin(line);
        int toy;
		stack<int> s1;
		stack<int> s2;
		bool flag=false;
		while(sin>>toy){
			if(toy<0){
				s1.push(toy);
				if(s2.size()!=0) s2.top()+=(toy);
				s2.push(0);
			}else{
				if(toy!=(-1*s1.top())) break;
				if(s2.top()<=s1.top()) break;
				s1.pop();
				s2.pop();
			}
			if(s1.empty()){	
				if(sin>>toy) break;	
				flag=true;
				break;
			}
		}
		if(flag) cout<<":-) Matrioshka!"<<endl;
		else	cout<<":-( Try again."<<endl;
    }
    return 0;
}