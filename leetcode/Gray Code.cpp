//����1���ٶȰٿƣ� �ݹ��������
//
//���ַ������ڸ������Ƿ��������ʵ�����õݹ�����¹��������죺
//1λ����������������
//(n+1)λ�������е�ǰ2n�����ֵ���nλ����������֣���˳����д����ǰ׺0
//(n+1)λ�������еĺ�2n�����ֵ���nλ����������֣���������д����ǰ׺1


//����2�� ֱ������������
//
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
		int max = 1<<n;
        for(int i=0;i<max;++i){
			ans.push_back(i^(i>>1));
        }
		return ans;
    }
};