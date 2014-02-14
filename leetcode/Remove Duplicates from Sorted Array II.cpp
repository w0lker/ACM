class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<3) return n;
        int pos = 2;
        int pp = A[0],p = A[1];
        for(int i=2;i<n;++i){
            if(A[i]!=pp){
                A[pos++]=A[i];
                pp = p;
                p = A[i];
            }
        }
        return pos;
    }
};