/**
��ӡ������Ҫ�ݹ麯��
������������1<<16��Ϊmin�ĳ�ʼֵ������Ȼ���С�1<<16ֻ��65536�������������ֵ��ʾ��̫С�ˡ�
**/

#include <cstdio>
#include <cstring>

const int INF = 0x7fffffff;  

int N;
int rst[11][11];
int rst_k[11][11];	//���i,jֱ��k��λ�����ڴ�ӡ���
struct Array{
	int row;
	int col;
};
Array arrs[11];



int dp(int i,int j){
	if(rst[i][j]>-1) return rst[i][j];
	rst_k[i][j]=i;
	if(i==j)  return rst[i][j] = 0;
	rst[i][j] = INF;
	for(int k=i;k<j;++k){
		int tmp = dp(i,k)+dp(k+1,j)+arrs[i].row*arrs[k].col*arrs[j].col;
		if(tmp<rst[i][j]){
			rst[i][j] = tmp;
			rst_k[i][j] = k;
		}
	}
	return rst[i][j];
}

void print(int i,int j){
	if(i>j) 
		return;
	if(i==j){
		printf("A%d",i+1);
		return ;
	}
	printf("(");
	print(i,rst_k[i][j]);
	printf(" x ");
	print(rst_k[i][j]+1,j);
	printf(")");
	return;
}


int main(){
	//freopen("data.txt","r",stdin);
	int loop = 0;
	while(scanf("%d",&N) && N){
		memset(arrs,0,sizeof(arrs));
		memset(rst,-1,sizeof(rst));
		memset(rst_k,-1,sizeof(rst_k));
		for(int i=0;i<N;++i){
			scanf("%d %d",&arrs[i].row,&arrs[i].col);
		}
		int aaa = dp(0,N-1);
		printf("Case %d: ",++loop);
		print(0,N-1);
		printf("\n");
		int tt = 0;
	}

	return 0;
}