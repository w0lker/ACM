/**
水题
**/
#include <iostream>
#include <cstring>	
using namespace std;

int test_num;
int period;
int parties[100];
int party_num;
int result;

int main_10050(){
	cin>>test_num;
	cin.get();
	while(test_num--){
		memset(parties,0,sizeof(parties));
		result = 0;
		cin>>period;
		cin>>party_num;
		for(int i=0;i<party_num;++i){
			cin>>parties[i];
		}
		for(int i=1;i<=period;){
			for(int j=0;j<party_num;j++){
				if(i%parties[j]==0){
					++result;
					break;
				}
			}
			if((i+2)%7==0) i+=3;	//周五、周六会直接跳过
			else ++i;
		}
		cout<<result<<endl;
	}
	return 0;
}