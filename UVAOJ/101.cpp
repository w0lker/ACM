/**
基本实现功能了，但是运行时间太长。
**/
#include <iostream>
#include <vector>
#include <string>
#include <map>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::map;

struct Block{
	Block(int i):num(i),up(NULL),down(NULL){}
	int num;
	Block *up;
	Block *down;
};
struct Pile{
	Pile(Block *b):top(b),bottom(b){}
	Block *top;
	Block *bottom;
	void pop(){
		if(top==NULL) return;
		else if(top==bottom){top=NULL;bottom=NULL;}
		else{
			top->down->up=NULL;
			top = top->down;
		}
	}
	void push(Block *blk){
		if(top==NULL) {
			blk->up=NULL;
			blk->down=NULL;
			top=blk;
			bottom=blk;}
		else{
			blk->down=top;
			top->up=blk;
			top=blk;
		}
	}
	
};

vector<Pile> piles;
vector<Block> blocks;
map<int,int> index;	
void pop_blocks(Block *blk){
		int p=index[blk->num];
		if(blk->down!=NULL){
			blk->down->up=NULL;
			piles[p].top=blk->down;
		}else{
			piles[p].top=NULL;
			piles[p].bottom=NULL;
		}
}
void push_blocks(Block *blk_a,Block *blk_top,int p){	
		Block *ptr=blk_a;
		while(ptr!=NULL){
			index[ptr->num]=p;	
			ptr=ptr->up;
		}
		if(piles[p].top==NULL){
			blk_a->down=NULL;
			piles[p].top=blk_top;
			piles[p].bottom=blk_a;
		}else{
			blk_a->down=piles[p].top;
			piles[p].top->up=blk_a;
			piles[p].top=blk_top;
		}
}

void move_onto(int a,int b){
	int p_a=index[a];
	int p_b=index[b];
	while(a!=(piles.at(p_a).top->num)){		
		int init_loca=piles.at(p_a).top->num;
		piles.at(p_a).pop();
		piles.at(init_loca).push(&blocks[init_loca]);	
	}
	while(b!=(piles.at(p_b).top->num)){	
		int init_loca=piles.at(p_b).top->num;
		piles.at(p_b).pop();
		piles.at(init_loca).push(&blocks[init_loca]);	
	}
	if(a!=(piles.at(p_a).top->num) && b!=(piles.at(p_b).top->num)){cout<<"不可能"<<endl;}
	piles.at(p_a).pop();
	piles.at(p_b).push(&blocks.at(a));
	index[a]=p_b;			
	
}
void move_over(int a,int b){
	int p_a=index[a];
	int p_b=index[b];
	while(a!=(piles.at(p_a).top->num)){	
		int init_loca=piles.at(p_a).top->num;
		piles.at(p_a).pop();
		piles.at(init_loca).push(&blocks[init_loca]);	
		index[init_loca]=init_loca;
		if(init_loca==b) p_b=init_loca;
	}
	move_onto(a,piles.at(p_b).top->num);
}
void pile_onto(int a,int b){
	int p_a=index[a];
	int p_b=index[b];
	while(b!=(piles.at(p_b).top->num)){		
		int init_loca=piles.at(p_b).top->num;
		piles.at(p_b).pop();
		piles.at(init_loca).push(&blocks[init_loca]);	
	}
	int top_num=piles.at(p_a).top->num;
	pop_blocks(&blocks[a]);	
	
	push_blocks(&blocks[a],&blocks[top_num],p_b);
}
void pile_over(int a,int b){	
	int top_num=piles.at(index[b]).top->num;
	pile_onto(a,top_num);
}


int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		Block block(i);
		blocks.push_back(block);
	}
	for(int i=0;i<n;i++){
		Pile pile(&blocks.at(i));
		piles.push_back(pile);
		index[i]=i;
	}
	int a,b;
	string s1,s2;
	while(true){
		cin>>s1;
		if(!s1.compare("quit")) break;
		cin>>a>>s2>>b;
		if(a==b) continue;
		if(s1.compare("move")==0){
			if(s2.compare("onto")==0) move_onto(a,b);
			else				   move_over(a,b);
		}else{
			if(s2.compare("onto")==0) pile_onto(a,b);
			else				   pile_over(a,b);
		}
	}
	for(int i=0;i<n;++i){
		cout<<i<<":";		
		Block *ptr=piles.at(i).bottom;
		while(ptr!=NULL){
			cout<<" "<<ptr->num;
			ptr=ptr->up;
		}
		cout<<endl;
	}
	return 0;
}