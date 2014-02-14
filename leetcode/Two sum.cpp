#include <vector>
using namespace std;
//复杂度O(nlog(n)) 用hashmap可以达到O(n)复杂度。
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> vec(numbers);
        //用插入排序法先进行排序
		for(int i=1;i<vec.size();++i){
			int tmp = vec[i];
			int j = i - 1;
			while(j>=0 && vec[j]>tmp){
				vec[j+1] = vec[j];
				--j;
			}
			vec[j+1] = tmp;
		}
		//求两个数和为target
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