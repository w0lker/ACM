//����˼·:��ÿ���㣬����һ�£����ܷ񵽴��յ㣬���ܵĻ���¼�µ�ǰ�ڵ���Сʣ��ֵ��
//�´α���ʱʣ��ֵС������ֱ�Ӽ�����
//���ǳ�ʱ��
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

//����Ľⷨ������A������A-B-C-D���õ�����Dʱʣ��ֵΪ�������B������Dʱʣ��ֵһ��Ҳ�Ǹ��ģ���Ϊ������ǵĻ�˵��A��BʱB�ϵ�ʣ��
//Ӧ���Ǹ��ģ���������������ôA-DҲ��Ȼ���У�,�������������Ǵ�A˳���ߵ�Bʱ,������D������ʱ��BҲ�Ͳ������ˣ�CҲ���ơ��������ֱ��
//����D��
//ע��һ���㲻��ֱ�ӷ���0,����Ҫ�ж�������cost�Ƿ����gas
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


//�����o(n)�ⷨ�� www.cnblogs.com/lautsie/p/3358311.html