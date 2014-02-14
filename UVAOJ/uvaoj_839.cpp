#include <cstdio>

int n;
bool rst;

int check(){
	int w1,d1,w2,d2;
	scanf("%d %d %d %d",&w1,&d1,&w2,&d2);
	int sum_w1(w1);
	int sum_w2(w2);
	if(!w1){
		sum_w1 = check();
	}
	if(!w2){
		sum_w2 = check();
	}
	if (sum_w1*d1!=sum_w2*d2) rst = false;
	
	return sum_w1+sum_w2;
}

int main_839(){
	freopen("data.txt","r",stdin);
	scanf("%d",&n);	
	while(n--){
		rst = true;
		check();
		printf("%s\n",rst?"YSE":"NO");
		if(n!=0) printf("\n");
	}
	return 0;
}