#include <cstring>
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if(n==0) return;
        if(m==0){ 
            memcpy(A,B,n*sizeof(int));
            return;
        }
        int end = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        while(true){
            if(B[j]>A[i]) A[end--] = B[j--];
            else          A[end--] = A[i--];
            if(i<0){
                while(j>=0) A[end--] = B[j--];
                break;
            }
            if(j<0){
                while(i>=0) A[end--] = A[i--];
                break;
            }
        }
    }
};