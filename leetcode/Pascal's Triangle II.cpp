//�����Խ����鿪��һά
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1,1);
        for(int i=1;i<=rowIndex;++i){
            int pre = 1;
			for(int j=1;j<i;++j){
			    int curr = ans[j];
				ans[j] = pre + curr;
				pre = curr;
			}
		}
        return ans;
    }
};

//ע�ⷵ�ص����кŶ��ڵ�vector

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pre(1,1);
        for(int i=1;i<=rowIndex;++i){
            vector<int> curr(i+1,1);
			for(int j=1;j<pre.size();++j){
				curr[j] = pre[j-1] + pre[j];
			}
			pre = curr;
		}
        return pre;
    }
};