#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
		string ans;
        int maxLen = INT_MAX;
        for(int i=0;i<strs.size();++i){
            maxLen = std::min(maxLen,(int)strs[i].size());
        }
        if(strs.empty() || maxLen==0) return "";
        bool stop = false;
        for(int k=0;k<maxLen;++k){
            char c = strs[0][k];
            for(int i=1;i<strs.size();++i){
                if(c!=strs[i][k]){
                    stop = true;
                    break;
                }
            }
            if(stop) break;
			else ans += c;
        }
        return ans;
    }
};