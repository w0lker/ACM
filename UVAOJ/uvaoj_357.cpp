#include <cstdio>  
#include <cstring>  

const int MAX = 30001;
long long result[MAX][6];	
int unit[5] = {50,25,10,5,1};	

//pre表示能用来拼凑数字的剩余coins的种类个数
//eg： pre=2表示只用用5和1来凑数字
long long dp(int num,int pre){
	if(result[num][pre]>0) return result[num][pre];
	long long &ans = result[num][pre];
	for(int j=pre;j<5;++j){
		if(num>unit[j] && dp(num-unit[j],j)) ans+=result[num-unit[j]][j];
		if(num==unit[j]) ans+=1;
	}
	return ans;
}

int main(){
	freopen("data.txt","r",stdin);
	memset(result,0,sizeof(result));
	int money;
	long long ans;
	while(scanf("%d",&money)!=EOF){
		ans = dp(money,0);
		if(ans>1) printf("There are %lld ways to produce %d cents change.\n",ans,money);
		else	  printf("There is only 1 way to produce %d cents change.\n",money);
	}
	return 0;
}

/** trick 解法
const int MAX = 30001;
long long result[MAX] = {1};	
int unit[5] = {1,5,10,25,50};	

int main(){
	//freopen("data.txt","r",stdin);
	for(int i=0;i<5;++i){
		for(int j=unit[i];j<MAX;++j){
			result[j] += result[j-unit[i]];
		}
	}
	int money;
	long long ans;
	while(scanf("%d",&money)!=EOF){
		ans = result[money];
		if(ans>1) printf("There are %lld ways to produce %d cents change.\n",ans,money);
		else	  printf("There is only 1 way to produce %d cents change.\n",money);
	}
	return 0;
}
**/
