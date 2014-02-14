/**
*	UVAOJ121 ֽ����Ϸ��
*	�ο���ַ��http://www.cnblogs.com/devymex/archive/2010/08/26/1808604.html
*	�����ύʱ��ʾstrcpy,strcat�б�������޷�ͨ����������vc2010�п���ͨ����
*	��һ�ֿ���accept�ķ�����http://blog.csdn.net/tclh123/article/details/7451401
**/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct CARD{
	char c[2];
};

inline bool match(CARD &c1,CARD &c2){
	return (c1.c[0]==c2.c[0] || c1.c[1]==c2.c[1]);
}
void m3(){
	std::vector<int> myvector;
  for (int i=1; i<=10; i++) myvector.push_back(i);
  myvector.erase (myvector.begin()+5);
   std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}
int main_uvaoj_127_1(){
	
	char p[200];
	string str="";
	while(true){
		typedef vector<CARD> PILE;
		vector<PILE> piles;
		getline(cin,str);
		if(str[0]=='#') break;
		strcpy(p,str.c_str());
		getline(cin,str);
		strcat(p,str.c_str());
		
		*remove(&p[0], &p[strlen(p)], ' ')='\0';	//�þ���
		for(int i=0;i<52;i++){
			PILE f_pile(1,((CARD*)&p)[i]);		//�þ���
			piles.push_back(f_pile);
			int j=piles.size()-1,k=0;
			while(true){
				if(j>=piles.size()) break;
				CARD curr=piles[j].back();
				for(k=j;k>0;){	//�����ǰ������Ż��ߵ�һ����ͬ��һֱ��ǰ�ƣ�����ֱ�ӽ���
					if(k>=3 && match(curr,piles[k-3].back()))	k-=3;
					else if(match(curr,piles[k-1].back()))		k-=1;
					else break;
				}
				if(k!=j){	//poker������ǰ�ƶ�
					piles[k].push_back(piles[j].back());
					piles[j].pop_back();
					if(piles[j].empty()) piles.erase(piles.begin()+j);			//erase vector��Ч�ʲ��Ǻܸߣ���Ҫ�ƶ������к�������Ԫ��
				}
				j=k+1;
			}

		}

		/**�������**/
		cout<<piles.size()<<" pile"<<((piles.size()>1)?"s":"")<<" remaining: ";
		for(int i=0;i<piles.size();i++){
			cout<<piles[i].size();
			if(i==piles.size()-1) cout<<endl;
			else cout<<" ";
		}
		
	}
	return 0;
}

