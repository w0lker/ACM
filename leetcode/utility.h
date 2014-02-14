#include <iostream>
using namespace std;

namespace Utility{

template<typename Iter>
void print(Iter begin,Iter end){
	while(begin!=end){
		cout<<*begin<<endl;
		++begin;
	}
}

};