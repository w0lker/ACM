//�ⷨ2����һ��table����ÿ��char��һ�γ��ֵ�λ�á�
//blog.csdn.net/cshaxu/article/details/12433931


//ע�⣺
//1 ÿ���ظ�ʱ���¼���������Ҫ�Ӹ��ظ�char��ʼ��
//2 ����s�����ظ������

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