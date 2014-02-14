/**
*uvaoj 133 功能实现了但是提交runtime error
**/
#include <iostream>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::list;

struct People{
	People(int i):index(i){}
	int index;
	People *s_people;	//顺时针下一个人
	People *n_people;  //逆时针下一个人
};

int N=10;
int n_remain;
int k=4;
int m=3;
People *ptr_s;	//顺时针计数的officer
People *ptr_n;	//逆时针计数的officer


void init(){
	n_remain=N;
	People *people = new People(1);
	People *p;
	ptr_n=people;
	for(int i=1;i<N;++i){
		p = new People(i+1);
		people->n_people=p;
		p->s_people=people;
		people=p;
	}
	ptr_s=p;
	ptr_s->n_people=ptr_n;
	ptr_n->s_people=ptr_s;
}
void remove(){
	for(int i=1;i<k;++i) ptr_n=ptr_n->n_people;
	for(int i=1;i<m ;++i)ptr_s=ptr_s->s_people;
	if(n_remain==1){
		cout<<(ptr_n->index>=10?" ":"  ")<<ptr_n->index;
		delete ptr_n;
		return;
	}
	ptr_n->s_people->n_people=ptr_n->n_people;
	ptr_n->n_people->s_people=ptr_n->s_people;
	cout<<(ptr_n->index>=10?" ":"  ")<<ptr_n->index;
	if(ptr_n!=ptr_s){
		n_remain--;
		cout<<(ptr_n->index>=10?" ":"  ")<<ptr_s->index;
		ptr_s->s_people->n_people=ptr_s->n_people;
		ptr_s->n_people->s_people=ptr_s->s_people;
	}
	
	People *n=ptr_n;
	People *s=ptr_s;
	ptr_n=ptr_n->n_people; if(ptr_n==s) ptr_n=ptr_n->n_people;// delete n;
	ptr_s=ptr_s->s_people; if(ptr_s==n) ptr_s=ptr_s->s_people;// delete s;
}

int main(){
	//cout<<"  4  8,  9  5,  3  1,  2  6, 10,  7"<<endl;
	while(true){
		cin>>N>>k>>m;
		if(!N) break;
		init();
		while(n_remain){
			if(n_remain!=N) cout<<",";
			remove();
			n_remain--;
		}
		cout<<endl;
	}
	//system("pause");
	return 0;
}