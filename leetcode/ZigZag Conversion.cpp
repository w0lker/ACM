#include<string>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows<=1) return s;
        int N = s.size();
        string ans(N,'0');
        int index = 0;
        int pos = 0;
        for(;pos<N;pos+=2*(nRows-1)){
            ans[index++] = s[pos];
        }
        for(int row=1;row<nRows-1;++row){
            int dev1 = 2*(nRows-row-1);
            int dev2 = 2*row;
            bool flag = true;
            pos = row;
            for(;pos<N;){
                ans[index++] = s[pos];
                if(flag) pos += dev1;
                else     pos += dev2;
                flag = !flag;
            }
			int aaa  =111;
        }
        pos = nRows-1;
        for(;pos<N;pos+=2*(nRows-1)){
            ans[index++] = s[pos];
        }
        return ans;
    }
};