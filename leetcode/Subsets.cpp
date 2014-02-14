//子集生成 增量构造法
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
		sort(S.begin(),S.end());
        vector<vector<int> > ans;
        for(int i=0;i<S.size();++i){
            vector<vector<int> > tmp;
            int val = S[i];
            vector<int> v(1,val);
            tmp.push_back(v);
            for(int j=0;j<ans.size();++j){
                vector<int> v(ans[j].begin(),ans[j].end());
                v.push_back(val);
                tmp.push_back(v);
            }
             for(int j=0;j<tmp.size();++j){
				 ans.push_back(tmp[j]);
			 }
        }
        //添入空集
        vector<int> v;
        ans.push_back(v);
		return ans;
    }
};