//疑问 为什么unordered_set不可以直接insert vector而set可以


#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > ans;
		int N = num.size();
		if(N<3) return ans;
		sort(num.begin(),num.end());
		int begin,end;
		set<int> exits;
		for(int i=0;i<num.size();++i){
			if(exits.find(num[i])!=exits.end()) continue;
			exits.insert(num[i]);
			int tar = -num[i];
			begin = i+1;
			end = N - 1;
			while(begin<end){
				int s = num[begin]+num[end];
				if(s==tar && begin!=i && end!=i){
					vector<int> vec;
					vec.push_back(num[i]);
					vec.push_back(num[begin]);
					vec.push_back(num[end]);
					sort(vec.begin(),vec.end());
					ans.push_back(vec);
					++begin;
					--end;
					//break;
				}else if(s>tar){
					--end;
				}else{
					++begin;
				}
			}
		}
		return ans;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//直接用set去重会超时的
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
		set<vector<int> > ans;
		int N = num.size();
		if(N<3) return vector<vector<int> >(ans.begin(),ans.end());
		sort(num.begin(),num.end());
		int begin,end;
		for(int i=0;i<num.size();++i){
			int tar = -num[i];
			begin = i+1;
			end = N - 1;
			while(begin<end){
				int s = num[begin]+num[end];
				if(s==tar && begin!=i && end!=i){
					vector<int> vec;
					vec.push_back(num[i]);
					vec.push_back(num[begin]);
					vec.push_back(num[end]);
					sort(vec.begin(),vec.end());
					ans.insert(vec);
					++begin;
					--end;
				}else if(s>tar){
					--end;
				}else{
					++begin;
				}
			}
		}
		return vector<vector<int> >(ans.begin(),ans.end());
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Output Limit Exceeded
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > ans;
		int N = num.size();
		if(N<3) return ans;
		sort(num.begin(),num.end());
		int begin,end;
		int pre = INT_MIN,curr;
		for(int i=0;i<num.size();++i){
			curr = num[i];
			if(curr==pre) continue;
			pre = curr;
			int tar = -num[i];
			begin = i+1;
			end = N - 1;
			while(begin<end){
				int s = num[begin]+num[end];
				if(s==tar && begin!=i && end!=i){
					vector<int> vec;
					vec.push_back(num[i]);
					vec.push_back(num[begin]);
					vec.push_back(num[end]);
					sort(vec.begin(),vec.end());
					ans.push_back(vec);
					++begin;
					--end;
					//break;
				}else if(s>tar){
					--end;
				}else{
					++begin;
				}
			}
		}
		return ans;
    }
};





//会超时，而且由于重复导致利用的空间过大
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > ans;
		if(num.size()<3) return ans;
		sort(num.begin(),num.end());
		int begin,end,mid,tar;
		for(int i=0;i<num.size();++i){
			for(int j=i+1;j<num.size();++j){
				begin = j+1;
				end = num.size()-1;
				tar = -(num[i]+num[j]);
				//二分查找
				while(begin<=end){
					mid = (begin+end)/2;
					if(num[mid]==tar && mid!=i && mid!=j){
						vector<int> v;
						v.push_back(num[i]);
						v.push_back(num[j]);
						v.push_back(num[mid]);
						sort(v.begin(),v.end());
						ans.push_back(v);
						break;
					}else if(tar<num[mid]){
						end = mid - 1;
					}else{
						begin = mid + 1;
					}
				}
			}
		}
		ans.erase(unique(ans.begin(),ans.end()),ans.end());
		return ans;
    }
};