
//Every person can take only one object of each kind，每样只能拿一个！！
//也是凑数字,拿各种商品的price凑出最最大的数（且要求weight之和不大于capacity）

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int LIMIT = 1001;

int T;
int N;
int P;
int price[LIMIT];
int weight[LIMIT];
int capacity[LIMIT];
int rst[LIMIT];

int dp(int c){	//包裹剩余空间
	if(rst[c]>-1) return rst[c];
	rst[c] = 0;
	for(int j=0;j<N;++j){
		if(c>=weight[j]){
			int tmp = dp(c-weight[j])+price[j];
			if(tmp>rst[c] ) rst[c] = tmp;
		}
	}
	return rst[c];
}

int main(){
	freopen("data.txt","r",stdin);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i=0;i<N;++i)	scanf("%d %d",&price[i],&weight[i]);
		scanf("%d",&P);
		int sum = 0;
		int capa;
		for(int i=0;i<P;++i){
			scanf("%d",&capa);
			memset(rst,0,sizeof(rst));
			for(int j=0;j<N;++j){
				for(int k=capa;k>=weight[j];--k){
					rst[k] = max(rst[k],rst[k-weight[j]]+price[j]);
				}
			}
			sum += rst[capa];
		}
		/*ans = 0;
		for(int i=0;i<P;++i){
			memset(rst,-1,sizeof(rst));
			ans += dp(capacity[i]);
		}*/
		printf("%d\n",sum);	
	}

	return 0;
}