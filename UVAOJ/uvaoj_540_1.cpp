/**
team queue和普通queue区别就是在push的时候，如果queue中有和当前元素同组的，则将当前元素push到改组元素的后面
否则push到整个queue的后面。
解题用queue装queue.push元素时，找到当前元素所在team的queue,push进去，如果当前team没有元素在queue中，则产生一个
queue，push到大queue中。
**/
#include <map>
#include <queue>
#include <iostream>
#include <string>
using namespace std;

int t_num;
map<int,int> elem_team;
map<int,queue<int> *> q_map;
queue<queue<int>* > t_queue;
int loop=1;
vector<int> result;
int main_540_1(){
	while(cin>>t_num){
		if(!t_num) break;
		cin.get();
		int elem_num;
		int elem;
		string command;
		int i=0;
		while(t_num--){
			cin>>elem_num;
			while(elem_num--) {
				cin>>elem;
				elem_team.insert(pair<int,int>(elem,i));
			}
			i++;
		}
		while(cin>>command){
			if(command=="STOP") break;
			if(command=="ENQUEUE"){
				cin>>elem;
				map<int,queue<int> *>::iterator itr = q_map.find( elem_team[elem] );
				if(itr==q_map.end()){
					queue<int> *q = new queue<int>;
					q->push(elem);
					t_queue.push(q);
					q_map.insert(pair<int,queue<int>* >( elem_team[elem],q));
				}else{
					itr->second->push(elem);
				}
			}else if(command=="DEQUEUE"){
				elem = t_queue.front()->front();
				result.push_back(elem);
				t_queue.front()->pop();
				if(t_queue.front()->empty()){
					t_queue.pop();
					q_map.erase(elem_team[elem]);
				}
			}
		}
			
		cout<<"Scenario #"<<loop++<<endl;
		for(vector<int>::iterator itr=result.begin();itr!=result.end();++itr)
			cout<<*itr<<endl;
		cout<<endl;
		
		result.clear();
		elem_team.clear();
		while(!t_queue.empty()) t_queue.pop();
		q_map.clear();
	}
	return 0;
}