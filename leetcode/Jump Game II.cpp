#include <algorithm>
using namespace std;

class Solution {
public:
    bool jump(int A[], int n) {
		int curr = 0 ;
		int num = 0;
		int last = -1;
		for(int i=0;i<n;++i){
			if(i > last){
				last = curr;
				num++;
			}
			curr = max(curr,i+A[i]);
		}
		return num;
    }
};


//dfs ³¬Ê±
class Solution {
	int jump(int A[],int pos,int n){
		if(pos>=n-1) return 1;
		int maxPos = pos;
		for(int i=1;i<=A[pos];++i){
			if(pos+i+A[pos+i] > maxPos+A[maxPos]) maxPos = pos + i;
		}
		return 1+jump(A,maxPos,n);
	}
public:
    bool jump(int A[], int n) {
		if(n<=1) return 0;
        return jump(A,0,n);
    }
};