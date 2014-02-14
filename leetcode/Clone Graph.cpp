/**
广度优先遍历
**/
#include <queue>
#include <vector>
#include <map>
#include <iostream>
#include <utility>
using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(node==NULL) return NULL;
        typedef UndirectedGraphNode UGN;
		map<int,UGN*> m;
		queue<UGN*> q;
		UGN *new_node = new UGN(node->label);
		UGN *ans = new_node;
		m.insert(make_pair(node->label,new_node));
		q.push(node);
		while(!q.empty()){
			UGN *node = q.front();
			q.pop();
			UGN *new_node = m.find(node->label)->second;	//从queue中拿出来的UGN一定已经建立好节点了。
			for(size_t i = 0;i<node->neighbors.size();++i){
				UGN *neigh = node->neighbors[i];
				UGN *new_neigh;
				map<int,UGN*>::iterator iter = m.find(neigh->label);
				if(iter==m.end()){
					new_neigh = new UGN(neigh->label);
					m.insert(make_pair(new_neigh->label,new_neigh));
					q.push(neigh);
				}
				else  new_neigh = iter->second;
				new_node->neighbors.push_back(new_neigh);
			}
		}
		return ans;
    }
};