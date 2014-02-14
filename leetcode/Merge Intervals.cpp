//未完成

#include <algorithm>
#include <vector>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> ans;
		int N = intervals.size();
		int S = newInterval.start,E = newInterval.end;
		bool flag = false;		//判断newInterval是否不包含在某个区间中
		int i = 0;
		for(;i<N;++i){
			if(intervals[i].end<S){
				ans.push_back(intervals[i]);
			}else{
				S = min(S,intervals[i].start);
				break;
			}
		}
		if(intervals[i].end<E) flag = true;
		for(;i<N;++i){
			if(intervals[i].end<E){
				ans.push_back(intervals[i]);
			}else{
				E = max(E,intervals[i].end);
				++i;
				break;
			}
		}
		if(flag){
			Interval inter(S,E);
			ans.push_back(inter);
		}
		for(;i<N;++i){
			ans.push_back(intervals[i]);
		}
		return ans;
    }
};