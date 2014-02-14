//参考网址: online-judge.uva.es/board/viewtopic.php?f=59&t=76073

//#include <cstdlib>
#include <cstdio>
#include <cstring>
//#include <ctype.h>
//#include <math.h>
int n;		//测试次数
char s[300][300];
int k;		//行数

void dfs(int r,int low,int high){
	for(int i=low;i<high && i<strlen(s[r]);++i){
		if(s[r][i] && s[r][i]!=' ' && s[r][i]!='\n'){
			printf("%c%c",s[r][i],'(');
			if(r+2<k && s[r+1][i]=='|'){
				int left(i);
				while(s[r+2][left]=='-') 
					--left;
				++left;
				int right(i);
				while(s[r+2][right]=='-')
					++right;
				dfs(r+3,left,right);
			}
			printf("%c",')');
		}
	}

}
int main(){
	freopen("data.txt","r",stdin);
	scanf("%d",&n);
	getchar();
	while(n--){
		//memset(s,'\0',sizeof(s));
		k = 0;
		while(true){
			fgets(s[k],210,stdin);
			if(s[k][0]=='#') break;
			++k;
		}
		printf("%c",'(');
		dfs(0,0,k);
		printf("%c\n",')');
	}
	return 0;
}