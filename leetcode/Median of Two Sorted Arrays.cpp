#include <algorithm>
using namespace std;

int findKth(int A[],int m,int B[], int n,int k){
	if(m<n) return findKth(B,n,A,m,k);
	if(n==0) return A[k-1];
	if(k==1) return min(A[0],B[0]);
	int k2 = min(n,k/2);
	int k1 = k - k2;
	if(A[k1-1]<B[k2-1])
		return findKth(A+k1,m-k1,B,n,k-k1);
	if(B[k2-1]<A[k1-1])
		return findKth(A,m,B+k2,n-k2,k-k2);
	return A[k1-1];

}

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
       int x = findKth(A,m,B,n,(m+n+1)/2);
	   if(((m+n)&1)) return x;
	   else	 return (x+findKth(A,m,B,n,(m+n+1)/2+1))/double(2);
    }
};


//思路和上面的解法很类似，但是没有想到转换成求第k大的数，而是在A，B中反复折半移动找到第k大和k+1大的树，
//而且采用了迭代方法，各种边界情况无法应付了。。。
//#include <algorithm>
//using namespace std;
//
//class Solution {
//private: 
//	double test(int A[], int m, int B[], int n,char *state);
//public:
//    double findMedianSortedArrays(int A[], int m, int B[], int n) {
//        char *state;
//		double ans = test(A,m,B,n,state);
//		if(strcmp(state,"success")==0) return ans;
//		ans = test(B,n,A,m,state);
//		return ans;
//    }
//};
//
//double help(int a,int b,int c){
//	return (a+b+c-max(max(a,b),c))/double(2);
//}
//
//double Solution::test(int A[], int m, int B[], int n,char *state){
//	state = "success";
//	int k = m+n;
//	int hk = (k-1)/2;	//需要判断k<=1的情况
//	bool isEven = ((k&1)==0);
//	int low = 0;
//	int up = min(m,k);
//	int mid;
//	int k1,k2;
//	while(low<=up){
//		mid = (low+up)/2;
//		k1 = max(0,mid);
//		k2 = min(n,2*hk-k1);
//		if((k1>0 && A[k1-1]<=B[k2])
//		  &&(k2>0 && B[k2-1]<=A[k1]))
//		{
//			return isEven?((A[k1]+B[k2])/double(2)):min(A[k1],B[k2]);
//		}
//		if(k1==0){
//			state = "success";
//			return help(A[0],B[k2],B[k2+1]);
//		}
//		if(k2==0){
//			state = "success";
//			return help(B[0],A[k1],A[k1+1]);
//		}
//		if(A[k1-1]>=B[k2]) up = mid - 1; 
//		if(B[k2-1]>=A[k1]) low = mid + 1; 
//	}
//	state = "fail";
//	return -1;
//}

//测试用例
//const int n = 5;
//	const int m = 6;
//	int A[m] = {1,4,4,6,8,9};
//	int B[n] = {2,3,5,5,10};
//	Solution s;
//	cout<<s.findMedianSortedArrays(A,m,B,n)<<endl;