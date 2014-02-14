//注意*号的含义不是代表任意多个字符，而是表示*号前面的字符可以出现0次~任意次

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
		if(*p=='\0') return *s=='\0';

		/*if(*s=='\0'){
			if(*p=='\0') return true;
			else if(*(p+1)!='*') return false;
		}*/
		
	   if(*(p+1)!='*'){
			if(*p!='.' && *p!=*s) return false;//return false;
			else return isMatch(s+1,p+1); 
	   }else{
			while(*s!='\0' && *p==*s){
				if(isMatch(s,p+2)) return true;
				++s;
			}
			return isMatch(s,p+2);
	   }
    }
};


