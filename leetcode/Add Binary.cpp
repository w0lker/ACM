

//注意 char c = 0 和 char c = '0'的区别
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size()<b.size()) swap(a,b);
        int MAX_LEN = a.size(),MIN_LEN = b.size();
        string ans(MAX_LEN,'0');
        int flag = 0;
        for(int i=1;i<=MAX_LEN;++i){
            int v1 = a[MAX_LEN-i]=='0'?0:1;
            int v2 = 0;
            if(i<=MIN_LEN){
                v2 = b[MIN_LEN-i]=='0'?0:1;
            }
            int v = v1+v2+flag;
            ans[MAX_LEN-i] = v%2?'1':'0';
            flag = (v>=2)?1:0;
        }
        return (flag)?("1"+ans):ans;
    }
};