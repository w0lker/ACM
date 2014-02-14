#include<algorithm>
using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
        int pa=0,pb=n-1;
		for(int i=0;i<=pb;){
			if(A[i]==0){
				swap(A[i],A[pa]);
				++pa;
				++i;
			}else if(A[i]==2){
				swap(A[i],A[pb]);
				--pb;
			}else ++i;
		}
    }
};