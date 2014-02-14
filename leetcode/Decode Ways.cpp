

//错误的思路，要处理一大堆例外情况~~~，还没有pass
#include <string>
#include <iostream>
using namespace std;

class Solution {
	bool valid(string &s,int pos){
		if(s[pos-1]=='1'  || (s[pos-1]=='2' && s[pos]<'7')) return true;
		else	return false;
	}
public:
    int numDecodings(string s) {
		/*int i;
		for(i=0;i<s.size() && s[i]=='0';++i) ;
		s = s.substr(i,s.size()-i);*/
		if(s.empty() || s[0]=='0') return 0;
		if(s.size()==1) return 1;
		int p,pp,ans;
		if(s[1]!='0' && (s[0]=='1' || (s[0]=='2' && s[1]<'7'))) {
			pp = 1;
			p = 2;
		}else{
			pp = p = 1;
		}
		ans = p;
		for(int i=2;i<s.size();++i){
			//if(
			if(s[i]=='0'){
				if(s[i-1]!='1' && s[i-1]!='2') return 0;
				pp = p;
				ans = p;
				continue;
			}
			if(valid(s,i)){
				ans = p + pp;
				pp = p;
				p = ans;
			}else{
				ans = p;
				pp = p;
			}
		}
		return ans;
    }
};