#include <vector>
using namespace std;
//���Ӷ�O(nlog(n)) ��hashmap���ԴﵽO(n)���Ӷȡ�
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> vec(numbers);
        //�ò��������Ƚ�������
		for(int i=1;i<vec.size();++i){
			int tmp = vec[i];
			int j = i - 1;
			while(j>=0 && vec[j]>tmp){
				vec[j+1] = vec[j];
				--j;
			}
			vec[j+1] = tmp;
		}
		//����������Ϊtarget
		int begin = 0,end = vec.size() - 1;
		vector<int> ans;
		while(true){
			int sum = vec[begin] + vec[end];
			if(sum>target){
				--end;
				continue;
			}else if(sum<target){
				++begin;
				continue;
			}
			else{
				for(int i=0;i<vec.size();++i){
					if(numbers[i]==vec[begin]) {ans.push_back(++i);}
					if(numbers[i]==vec[end]) {ans.push_back(++i);}
				}
				
				return ans;
			}
		}

    }
};