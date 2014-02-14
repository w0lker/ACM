//清晰正确的写法:
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

//混乱的写法，画蛇添足
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
			//上面两行明显没有必要，可以合并的
			if(i==n) break;
            pre = A[i];
            A[pos++] = A[i];
        }
        return pos;
    }
};