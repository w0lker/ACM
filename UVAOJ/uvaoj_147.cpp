/**
此题解法很巧妙，解题网址：www.cnblogs.com/devymex/archive/2010/08/27/1808714.html
首先，考虑全部用5来凑数字，当然每个数字只有一种答案了。
其次，考虑用5和10两个来凑数字,再利用动态规划，每个数字的答案f(x),等于f(x-10)+1,1代表全部用5来凑成x，f(x-10)表示从
	x中扣除1个10后形成的数字的答案数目。举个栗子，15可以由(全是5,1个10+1个5）两种情况，75可以由(全是5,1个10+65),而其中的
	65能由多少中情况组成在求75之前已经求出来了。
	再后来，考虑用5、10、20三个数字来凑，每个数字的答案f(x)=f(x-20)+(只由5、10来凑x的答案数目)。再举个栗子：
	20=（一个20,全由5、10来凑）,25=(20+5,全由5,10来凑)，其中全由5、10来凑的答案上一轮已经求出来了,而f(5)=1也已经求出。
	75=(20+55,全由5、10来凑)其中全由5、10来凑的答案上一轮已经求出来了,而f(55)在求f(75)之前也已经求出。
以此类推

tips:
1、输出long long要用%lld
2、long long result[MAX] = {1};		//只有第一个初始化为1
3、memset(result,1,sizeof(result));	//错误，这样产生的不是全为1的数组
4、输出是money 和答案都是右靠齐的。"  0.02"而不是"0.02  "
**/
#include <cstdio>  
#include <cstring>  
using namespace std;

const int MAX = 6001;
long long result[MAX] = {1};	
int unit[11] = {1,2,4,10,20,40,100,200,400,1000,2000};	

int main(){
	freopen("data.txt","r",stdin);
	for(int i=0;i<11;++i){
		for(int j=unit[i];j<MAX;++j){
			result[j] += result[j-unit[i]];
		}
	}
	float money;
	while(scanf("%f",&money) && money>0.04){
		printf("%6.2f%17lld\n",money,result[int(20*money+0.5f)]);
	}
	return 0;
}
