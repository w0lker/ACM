#include <vector>
#include<algorithm>
using namespace std;

class Solution{
	public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		bool isEven = ((m+n)%2==0);
		vector<int> vec;
		int half = (m+n)/2+1;
		vec.reserve(half+1);
		int i=0;
		int j=0;
		int loop = 0;
		while((loop++)<half){
			if(n==0){
				vec.push_back(A[i++]);
				continue;
			}
			if(m==0){
				vec.push_back(B[j++]);
				continue;
			}
			if(i<m && (j==n || A[i]<=B[j])){
				vec.push_back(A[i++]);
			}else{
				vec.push_back(B[j++]);
			}
		}
		if(isEven) return(double(vec[half-1]+vec[half])/2);
		else		return vec[half-1];
    }
};