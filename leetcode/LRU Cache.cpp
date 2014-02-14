/**
用map保存key-val对，用双向链表表示key的新旧程度
注意当capacity为1、2时的特殊情况
注意当cache量为capacity时，再插入新的cache需要删除最早一个。
**/

#include<map>
using namespace std;

struct Node{
	Node(int k):key(k){}
	int key;
	Node *pre;
	Node *next;
};

class LRUCache{
private:
	Node *head;
	Node *tail;
	map<int,int> m;
	int capacity;
	int curr_capa;
	void update(int key);
	void add(int key);
	void remove();
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
		head = tail = NULL;
		curr_capa = 0;
    }
    
	int get(int key) {
		map<int,int>::iterator iter = m.find(key);
		if(iter==m.end()) return -1;
		update(key);
		return iter->second;
    }
    
    void set(int key, int value) {
        map<int,int>::iterator iter = m.find(key);
		if(iter!=m.end()){
			m[key] = value;
			update(key);
		}else{
			if(curr_capa++>=capacity){
				remove(); 
				curr_capa = capacity;
			}
			m.insert(make_pair(key,value));
			add(key);
		}
    }
};

void LRUCache::update(int key){
	if(head==tail) return;
	Node *n = head;
	while(n!=tail && (n->key)!=key) n = n->next;
	if(n==head) return;
	if(n!=tail){
		n->pre->next = n->next;
		n->next->pre = n->pre;
	}else{
		tail = tail->pre;
		tail->next = NULL;
	}
	head->pre = n;
	n->next = head;	n->pre = NULL;
	head = n;
}

void LRUCache::add(int key){
	Node *n = new Node(key);
	if(head==NULL) head = tail = n;
	else{
		n->next = head;
		head->pre = n;
		head = n;
	}
}

void LRUCache::remove(){
	if(head==NULL) return;	//容量为1
	m.erase(tail->key);
	if(head==tail){	//容量为2
		head = tail = NULL;	
		return;
	}
	Node *n = tail;
	tail = tail->pre;
	tail->next = NULL;
	delete n;
}

//测试数据：
/*LRUCache lru(4);
	int a1= lru.get(4);
	lru.set(11,8);
	int a2 = lru.get(11);
	lru.set(12,7);
	lru.set(13,6);
	lru.get(12);
	lru.set(14,5);
	lru.set(15,2);*/
	//2,[set(2,1),set(1,1),get(2),set(4,1),get(1),get(2)]
	/*LRUCache lru(2);
	lru.set(2,1);
	lru.set(1,1);
	cout<<lru.get(2)<<endl;
	lru.set(4,1);
	cout<<lru.get(1)<<endl;
	cout<<lru.get(2)<<endl;*/