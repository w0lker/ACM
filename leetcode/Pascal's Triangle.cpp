////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//µü´ú
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int> > generate(int numRows) {
		vector<vector<int> > ans;
		if(numRows==0) return ans;
        vector<int> vec(1,1);
		ans.push_back(vec);
        for(int i=1;i<numRows;++i){
			vec.clear();
			vec.push_back(1);
			for(int j=1;j<ans[i-1].size();++j){
				vec.push_back(ans[i-1][j-1] + ans[i-1][j]);
			}
			vec.push_back(1);
			ans.push_back(vec);
		}
        return ans;
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include<vector>
using namespace std;


class Solution {
    vector<vector<int> > ans;
    void helper(int row){
        ans[row].push_back(1);
        if(row==0) return;
        if(row>1){
            for(int i=1;i<ans[row-1].size();++i){
                ans[row].push_back(ans[row-1][i-1]+ans[row-1][i]);
            }
        }
        ans[row].push_back(1);
    }
public:
    vector<vector<int> > generate(int numRows) {
        vector<int> vec;
        for(int i=0;i<numRows;++i) ans.push_back(vec);
        for(int i=0;i<numRows;++i) helper(i);
        return ans;
    }
};