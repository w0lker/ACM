//解法2：用一个table保存每个char上一次出现的位置。
//blog.csdn.net/cshaxu/article/details/12433931


//注意：
//1 每次重复时重新计数，但是要从该重复char开始计
//2 整个s都不重复的情况

#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int ans = 0;
        int tmp = 0;
        unordered_set<char> exits;
		int pos = 0;
        for(int i=0;i<s.size();++i){
            char c = s[i];
            if(exits.find(c)==exits.end()){
                ++tmp;
				if(i==s.size()-1) ans = max(ans,tmp);
            }else{
				ans = max(ans,tmp);
				int j=pos;
				for(;j<i && s[j]!=s[i];++j){
					exits.erase(s[j]);
				}
				exits.erase(s[j]);
                tmp = i - j;
				pos = j + 1;
            }
            exits.insert(c);
        }
        return ans;
    }
};