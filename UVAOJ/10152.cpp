/**
uvaoj_10152 ������� runtime:0.039
�ο���http://blog.csdn.net/bluecat56/article/details/9007485
	  http://m.blog.csdn.net/blog/hcbbt/9266429
˵������Ϊ�ڹ�ֻ������stack�Ķ��ˣ����ң���������������棬���������������棨�����ƶ������ڹ��У�
	  ����ֻ��Ҫ������ж���ֻ�ڹ걻�ƶ�������Ϊcount�����ˡ�
	  ���㷽�������¶�����ԭʼstack��init��Ŀ��stack:tar֮��Ƚϡ����ֲ�һ�µ����count��1��
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