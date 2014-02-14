

//�ⷨ1////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//����һ��ͼģ�ͣ��ܹ�ͨ��һ���޸ı����ͬ�ĵ���֮����һ���ߣ������·
//2292 msѹ�߹��ˡ���
//���ֽⷨ����������word֮���ܷ�仯�������е��˷ѣ������������ÿ�αȽ�ֻȡstart��ǰλ�õ�ƥ���word
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

struct Node{
    string val;
    bool vis;
    int depth;
    vector<Node*> neigh;
    Node(const string &str):val(str),vis(false),depth(0) {}
};

class Solution {
    int LEN;    //���ʳ���
    vector<Node*> nodes;
    bool valid(const string &wa,const string &wb){
        int cnt = 0;
        for(int i=0;i<LEN;++i){
            if(wa[i]!=wb[i]){
                if(++cnt>1) return false;
            }
        }
        return true;
    }
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if( (LEN = start.size()) ==0) return 0;
        Node *startNode = new Node(start);
        Node *endNode = new Node(end);
        nodes.push_back(startNode);
        nodes.push_back(endNode);
		for(unordered_set<string>::const_iterator iter = dict.begin();iter!=dict.end();++iter){
			Node *node = new Node(*iter);
            nodes.push_back(node);
		}
        for(int i=0;i<nodes.size()-1;++i){
            for(int j=i+1;j<nodes.size();++j){
                if(valid(nodes[i]->val,nodes[j]->val)){
                    nodes[i]->neigh.push_back(nodes[j]);
                    nodes[j]->neigh.push_back(nodes[i]);
                }
            }
        }
        queue<Node*> q;
        startNode->vis = true;
        startNode->depth = 1;
        q.push(startNode);
        while(!q.empty()){
            Node *node = q.front();
            q.pop();
            for(int i=0;i<node->neigh.size();++i){
                Node *ne = node->neigh[i];
                if(!ne->vis){
                    ne->vis = true;
                    ne->depth = 1 + node->depth;
                    q.push(ne);
                }
            }
        }
        return endNode->depth;
    }
};