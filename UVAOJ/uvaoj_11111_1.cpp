#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main_11111_1(){
	while(true){
		vector<int> toys;
		string line;
		getline(cin,line);
		char *toy = strtok(const_cast<char*>(line.c_str())," ");
		while(toy!=NULL){
			int tmp = atoi(toy);
			toys.push_back(tmp);
			toy = strtok(NULL," ");
		}
		stack<int> s1;
		stack<int> s2;
		bool flag=false;
		for(vector<int>::iterator itr=toys.begin();itr!=toys.end();++itr){
			if(*itr<0){
				s1.push(*itr);
				if(s2.size()!=0) s2.top()+=(*itr);
				s2.push(0);
			}else{
				if(*itr!=(-1*s1.top())) {break;}
				if(s2.top()<=s1.top()) {break;}	
				s1.pop();
				s2.pop();
			}
			if(s1.empty()){		//��ʱ�����ж�vector�Ƿ�Ϊ�գ���Ϊ��������ֻ����һ��
				flag=true;
				break;
			}
		}
		if(flag) cout<<":-) Matrioshka!"<<endl;
		else	cout<<":-( Try again."<<endl;
	}
	return 0;
}

