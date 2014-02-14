//不需要额外空间
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        //if(n==0) return 0;
        int pos = n-1;
        for(int i=n-1;i>=0;--i){
            if(A[i]!=elem){
                A[pos--] = A[i];
            }
        }
        if(pos<n-1) copy(A+pos+1,A+n,A);
        return n-1-pos;
    }
};
//用额外的空间
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(n==0) return 0;
        vector<int> vec;
        for(int i=0;i<n;++i)
            if(A[i]!=elem) vec.push_back(A[i]);
        int ans = vec.size();
        copy(vec.begin(),vec.end(),A);
        return ans;
    }
};