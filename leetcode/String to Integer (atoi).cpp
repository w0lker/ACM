//可以有前导的空白字符，在数字序列之后出现的任何非数字序列直接忽略不计
//当返回值超出整型返回时打印错误信息
//想当然了，误以为以数字0开头的只能是0,其他则错误如01、000891等(X).
//实际上测试用例中可以以0为头
//转换出错的情况返回值均未定义
//数字序列前以 + 或 - 号开头是可以的
//q: +0089正确？
//"2147483648" 返回"2147483647"
/**
afsa0fis
 iodf0
   -93ds
0923 sd02
9893293
-8239230
**/

#include<iostream>
using namespace std;


class Solution {
public:
    int atoi(const char *str) {
        int N = strlen(str);
		/*for(int i=0;i<N;++i)
			cout<<i<<" "<<"--"<<str[i]<<"---"<<endl;*/
        int s = 0;
        while(s<N && (str[s]==' ' || str[s]=='\t' ||
             str[s]=='\n' || str[s]=='\f' || str[s]=='\r')) ++s;
        long long ans = 0;
        bool neg = false;
        bool error = false;
		if(s==N) error = true;
		else{
            if(str[s]=='-'){
                neg = true;
                ++s;
            }else if(str[s]=='+') ++s;
			if(s==N) error = true;
			else{
				if(str[s]<'0' || str[s]>'9'){
					error = true;
				}else{
					while(s<N && (str[s]>='0' && str[s]<='9')){
						ans = 10*ans + (str[s]-'0');
						if(neg){
							if(ans>(INT_MAX+1)){
								ans = INT_MAX + 1;
								break;
							}
						}else{
							if(ans>INT_MAX){
								ans = INT_MAX;
								break;
							}
						}
						//cout<<ans<<" "<<INT_MAX<<"  "<<(ans>=INT_MAX)<<endl;
						++s;
					}
				}
			}
        }
        if(error) return 0;	//cout<<"转换出错"<<endl;
        return neg?-ans:ans;
    }
};