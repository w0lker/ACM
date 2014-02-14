#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
		int ans = 0;
        unordered_set<int> nums(num.begin(),num.end());
		unordered_set<int> delNums;
		for(int i=0;i<num.size();++i){
			int val = num[i];
			if(delNums.find(val)==delNums.end()){
				int tmp = 1;
				int up = val + 1;
				while(nums.find(up)!=nums.end()){
					++tmp;
					delNums.insert(up);
					++up;
				}
				int low = val - 1;
				while(nums.find(low)!=nums.end()){
					++tmp;
					delNums.insert(low);
					--low;
				}
				ans = max(ans,tmp);
			}
		}
		return ans;
    }
};