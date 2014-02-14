//������ȷ��д��:
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<2) return n;
        int pos = 1;
        for(int i=1;i<n;++i){
			if(A[i]!=A[pos-1]){
	            A[pos++] = A[i];
			}
        }
        return pos;
    }
};

//���ҵ�д������������
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<2) return n;
        int pre = A[0];
        int pos = 1;
        for(int i=1;i<n;++i){
            while(A[i]==pre) ++i;
			//������������û�б�Ҫ�����Ժϲ���
			if(i==n) break;
            pre = A[i];
            A[pos++] = A[i];
        }
        return pos;
    }
};