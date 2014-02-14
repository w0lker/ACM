//���� ��̬�滮
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.empty()) return word2.size();
		if(word2.empty()) return word1.size();
		int m = word1.size();
		int n = word2.size();
		int **dp = (int**)malloc((m+1)*sizeof(int*));
		for(int i=0;i<=m;++i){
			dp[i] = new int[n+1];
			memset(dp[i],0,sizeof(int)*(n+1));
			dp[i][0] = i;
		}
		for(int i=0;i<=n;++i)
			dp[0][i] = i;
		word1.insert(0,"0");
		word2.insert(0,"0");
		for(int i=1;i<=m;++i){
			for(int j=1;j<=n;++j){
				if(word1[i]==word2[j]) dp[i][j] = dp[i-1][j-1];
				else{
					int a = dp[i-1][j];		//��word1��ɾ��
					int b = dp[i][j-1];		//��word2��ɾ��
					int c = dp[i-1][j-1];	//�޸�word1��word2
					dp[i][j] = 1 + min(a,min(b,c));
				}
			}
		}
		int ans = dp[m][n];
		/*for(int i=0;i<=m;++i){
			delete [] dp[i];
		}*/
		return ans;
	}
};

//�ݹ� ��̬�滮
//��Ӧ�ô�����string�ĽǶȿ��ǣ���ʵֻҪ��һ������stringΪ��׼��
//���㽫�̵�stringת���ɳ���string����step�����ˡ�
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
	vector< vector<int> >dp;
	int ans,m,n;
	int minDistance(string &word1, string &word2,int i,int j) {
		if(i>=m || j>=n) return max(0,max(m-i,n-j));
		if(dp[i][j]!=-1) return dp[i][j];
		if(word1[i]==word2[j]) return minDistance(word1,word2,i+1,j+1);
		else{
			int a=0,b=0,c=0;
			a = minDistance(word1,word2,i,j+1);		//��word1�в���
			b = minDistance(word1,word2,i+1,j);		//��word1��ɾ��
			c = minDistance(word1,word2,i+1,j+1);	//�޸�word1
			dp[i][j] = 1 + min(a,min(b,c));
		}
		return dp[i][j];
    }
public:
    int minDistance(string word1, string word2) {
        m = word1.size();
		n = word2.size();
		if(m>n){
			swap(word1,word2);
			swap(m,n);
		}
		for(int i=0;i<m;++i){
			vector<int> vec(n,-1);
			dp.push_back(vec);
		}
		return minDistance(word1,word2,0,0);
    }
};
