////////////////////////////////////////////////////////////////////////////////////////////////////////////
//更清楚一点的代码
#include<cctype>
#include<string>
using namespace std;

class Solution {
    bool isValid(char c){
        return (c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='0'+9);
    }
public:
    bool isPalindrome(string s) {
        int N = s.size();
        int low = 0;
        int up = N-1;
        while(low<up){
			if(!isValid(s[low])) {
				++low;
				continue;
			}
			if(!isValid(s[up])){
				--up;
				continue;
			}
            if(s[low]!=s[up]){
              if((s[low]>='0' && s[low]<='0'+9) || (s[up]>='0' && s[up]<='0'+9)) 
				  return false;
              else if(toupper(s[low])!=toupper(s[up])) 
				  return false;  
            } 
            ++low;
            --up;
        }
        return true;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<cctype>

class Solution {
    bool isValid(char c){
        return (c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='0'+9);
    }
public:
    bool isPalindrome(string s) {
        int N = s.size();
        int low = 0;
        int up = N-1;
        while(low<up){
            while(low<N && low<up && !isValid(s[low])) ++low;
            if(low==up) break;
            while(up>=0 && up>low && !isValid(s[up])) --up;
            if(low==up) break;
            if(s[low]!=s[up]){
              if((s[low]>='0' && s[low]<='0'+9) || (s[up]>='0' && s[up]<='0'+9)) return false;
              else if(toupper(s[low])!=toupper(s[up])) return false;  
            } 
            ++low;
            --up;
        }
        return true;
    }
};