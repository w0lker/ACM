//Ҳ������������������Ӻ���ǰѰ�ҵ�һ���ǿո��ַ���һֱ��ǰ�ҵ�һ���ո��ַ�Ϊֹ��

//�״� "b   a    "��������ո�

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