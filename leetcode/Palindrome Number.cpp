class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int N = 1;
        int tmp = x;
        int small = 1,big = 1;
        while(tmp>=10){
            tmp /= 10;
            ++N;
            big *= 10;
        }
       for(int i=0;i<=N/2;++i){
		   if(((x/big)%10) != (x/small)%10) return false;
           small *= 10;
           big /= 10;
       }
        return true;
    }
};