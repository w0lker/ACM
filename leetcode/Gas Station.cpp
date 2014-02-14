//基本思路:对每个点，遍历一下，看能否到达终点，不能的话记录下当前节点最小剩余值，
//下次遍历时剩余值小于它就直接减掉。
//但是超时了
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
	int n;
	int next(int pos);
	int previous(int pos);
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		n = gas.size();
		if(n==1) return 0;
		if(n==0) return -1;
		vector<int> mrem,trem;
		mrem.assign(n,-1);
		for(int start = 0;start < n ; ++start){
			trem.assign(n,-1);
			int curr = start;
			while(true){
				if(curr==start) trem[curr] = gas[curr];
				else{
					int pre = previous(curr);
					trem[curr]  = gas[curr] + trem[pre] - cost[pre];
				}
				if(trem[curr]<=mrem[curr] || trem[curr]-cost[curr] < 0 ){
					int k = curr;
					while(k!=start){
						if(mrem[k]<trem[k]) mrem[k] = trem[k];
						k = previous(k);
					}
					break;
				}
				curr = next(curr);
				if(next(curr)==start)
					return start;
			}
		}
		return -1;
    }
};

int Solution::next(int pos){
	return pos==n-1?0:(pos+1);
}

int Solution::previous(int pos){
	return pos==0?n-1:(pos-1);
}

//巧妙的解法：若从A出发：A-B-C-D，得到到达D时剩余值为负，则从B出发到D时剩余值一定也是负的，因为如果不是的话说明A到B时B上的剩余
//应该是负的（否则若是正的那么A-D也必然可行）,反过来讲当我们从A顺利走到B时,当遇到D不可行时，B也就不可行了，C也类似。所以起点直接
//跳到D。
//注意一个点不是直接返回0,而是要判断这个点的cost是否大于gas
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if(gas.size()==1) return cost[0]>gas[0]?-1:0;
		int total=0,sum=0;
		int index = 0;
		for(int i=0;i<gas.size();++i){
			total += gas[i] - cost[i];
			sum += gas[i] - cost[i];
			if(sum<0){
				index = i;
				sum = 0;
			}
		}
		return total>=0?(index+1):-1;
    }
};


//另外的o(n)解法： www.cnblogs.com/lautsie/p/3358311.html