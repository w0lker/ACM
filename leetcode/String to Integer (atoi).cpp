//������ǰ���Ŀհ��ַ�������������֮����ֵ��κη���������ֱ�Ӻ��Բ���
//������ֵ�������ͷ���ʱ��ӡ������Ϣ
//�뵱Ȼ�ˣ�����Ϊ������0��ͷ��ֻ����0,�����������01��000891��(X).
//ʵ���ϲ��������п�����0Ϊͷ
//ת��������������ֵ��δ����
//��������ǰ�� + �� - �ſ�ͷ�ǿ��Ե�
//q: +0089��ȷ��
//"2147483648" ����"2147483647"
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
        if(error) return 0;	//cout<<"ת������"<<endl;
        return neg?-ans:ans;
    }
};