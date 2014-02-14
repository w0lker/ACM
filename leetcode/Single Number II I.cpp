//II
//½â·¨1£¬³¬Ê±£º
#include <cstring>
#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
		if(n<4) return A[0];
		int ans = 0;
		int bits[32];
		int a = 0;
		memset(bits,0,sizeof(bits));
        for(int i=0;i<n;++i){
			cout<<A[i]<<endl;
			for(int j=0;j<32;++j){
				bits[j] += ((A[i]>>j) &1);
			}
        }

		for(int j=0;j<32;++j) bits[j] %= 3;
		if(bits[31]==0) {
			for(int j=0;j<31;++j) if(bits[j]) ans += 1<<j;
		}else{
			for(int j=0;j<31;++j) bits[j] = bits[j]?0:1;
			for(int j=0;j<31;++j) if(bits[j]) ans += 1<<j;
			ans += 1;
			ans = -ans;
		}
		return ans;
    }
};

class Solution {
public:
    int singleNumber(int A[], int n) {
		if(n<4) return A[0];
		int ans = 0;
		int bits[32];
		int a = 0;
		memset(bits,0,sizeof(bits));
        for(int i=0;i<n;++i){
			cout<<A[i]<<endl;
			for(int j=0;j<32;++j){
				bits[j] += ((A[i]>>j) &1);
			}
        }
		if(bits[31]%3==0) {
			for(int j=0;j<31;++j) if(bits[j]%3) ans += 1<<j;
		}else{
			for(int j=0;j<31;++j) if(!(bits[j]%3)) ans += 1<<j;
			ans += 1;
			ans = -ans;
		}
		return ans;
    }
};

// 1
//class Solution {
//public:
//    int singleNumber(int A[], int n) {
//        int ans = 0;
//        for(int i=0;i<n;++i){
//            ans ^= A[i];
//        }
//		return ans;
//    }
//};