/**
uvaoj_10152 龟壳排序 runtime:0.039
参考：http://blog.csdn.net/bluecat56/article/details/9007485
	  http://m.blog.csdn.net/blog/hcbbt/9266429
说明：因为乌龟只能爬到stack的顶端，而且，最后爬的在最上面，最先爬的在最下面（所有移动过的乌龟中）
	  所以只需要算出来有多少只乌龟被移动过，记为count就行了。
	  计算方法是自下而上在原始stack：init和目标stack:tar之间比较。出现不一致的情况count加1。
**/

#include <cstring>
#include <cstdio>

int K;
int n;
char init[200+10][80+10];
char tar[200+10][80+10];

int main(){
		scanf("%d",&K);
	while(K--){
		scanf("%d",&n);
		getchar();
		for(int i=0;i<n;i++) gets(init[i]);
		for(int i=0;i<n;i++) gets(tar[i]);
		int count=0;
		for(int i=n-1,j=n-1;i>=0;){
			if(!strcmp(init[i],tar[j])){
				--i;--j;
			}else{
				--i,++count;
			}
		}
		for(int i=count-1;i>=0;--i){
			printf("%s\n",tar[i]);
		}
		printf("\n");
	}
	return 0;
}