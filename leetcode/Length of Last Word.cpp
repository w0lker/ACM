//也可以有其他方法例如从后往前寻找第一个非空格字符，一直往前找到一个空格字符为止。

//易错： "b   a    "连续多个空格

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int pre=0,curr=0;
        while(*s!='\0'){
            char c = *s;
            if((c>='a' && c<='z') || (c>='A' && c<='Z')) ++curr;
            else if(c==' ' && curr){
                pre = curr;
                curr = 0;
            }
            ++s;
        }
        return curr?curr:pre;
    }
};