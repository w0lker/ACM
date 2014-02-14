#include<iostream>
#include<string>

using namespace std;

int a2i[26];
int result;
char expr [111];

inline bool is_val( char c){
	return (c!='+' && c!='-');
}
inline bool is_opr(char c){
	return (c=='+' || c=='-');
}
int main2(){
	/*memset(expr,'0',111);
	cout<<expr<<"<<<"<<endl;*/
	char val;
	string line;
	while(getline(cin,line)){
		//还原操作：
		int index=0;
		//int index_i=0;
		for(int i=0;i<26;++i) a2i[i]=++i;
		result = 0;
		memset(expr,'0',111);
		//提出前置的++ 和 --
		//expr[index_e++]=line[index_i++];
		char e1='0';
		char e2='0';
		char e3='0';
		/*for(int i=line.size()-1;i>=0;++i){

		}*/
		int i = line.size()-1;
		val = line[i];

		while(i>=0){
			e1 = line [--i];
			e2 = line [--i];
			if(e1==e2){
			}else{

				while(is_opr(line[i])){
					
				}
			}
		}
	}
	


	return 0;
}