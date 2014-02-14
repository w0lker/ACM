#include<numeric>
#include<algorithm>
using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
		if(n<3) return 0;
        int *V = new int[n];
        int *leftHighest = new int[n];
        int highest = A[0];
        leftHighest[0] = A[0];
        for(int i=1;i<n;++i){
            leftHighest[i] = highest;
            if(highest<A[i]) highest = A[i];
        }
        highest = A[n-1];
        for(int i=n-2;i>0;--i){
            int v = min(leftHighest[i],highest) - A[i];
            V[i] = v>0?v:0;
            if(highest<A[i]) highest = A[i];
        }
		vector<int> vec(leftHighest,leftHighest+n);
		vector<int> vec2(V,V+n);
        return accumulate(V+1,V+n-1,0);
        //delete [] highst; delete [] V;//Ê¡ÂÔ
    }
};