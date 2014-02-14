// a = a + (b>c)?0:1 这个错误啊， 其等价于  a = （a + (b>c)）?0:1
//超时了
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
private:
	int n;
	int *dp;
	int get_min_pos(vector<int> &vec,int i,int j);
	void inner_candy(vector<int> &ratings,int i,int j);
public:
    int candy(vector<int> &ratings) {
        n = ratings.size();
		if(n==0) return 0;
		dp = new int[n];
		for(int i=0;i<n;++i) dp[i] = 0;
		inner_candy(ratings,0,n-1);
		int ans = 0;
		for(int i=0;i<n;++i){ans += dp[i]; cout<<dp[i]<<endl;}
		return ans;
    }
};

void Solution::inner_candy(vector<int> &ratings,int i,int j){
	if(i<0 || j>=n){
		cout<<"严重错误"<<endl;
	}
	if(i==j){
		dp[i] = 1;
		if(i>0 && ratings[i]>ratings[i-1]) dp[i] = dp[i-1] + 1;
		if(i<n-1 && ratings[i]>ratings[i+1]) dp[i] = max(dp[i],dp[i+1]+1);
		return ;
	}
	//递归
	int pos = get_min_pos(ratings,i,j);
	
	if(pos==i && i>0 && ratings[pos]>ratings[pos-1]){
		dp[pos] = 1 + dp[pos-1];
	}else if(pos==j && j<n-1 && ratings[pos]>ratings[pos+1]){
		dp[pos] = 1 + dp[pos+1];
	}else{
		dp[pos] = 1;
	}
	int pos1=pos,pos2=pos;

	while(pos1>i && ratings[pos1-1]>=ratings[pos1]){
		int tmp = dp[pos1] + ((ratings[pos1]==ratings[pos1-1])?0:1);
		if(dp[pos1-1] < tmp)  dp[pos1-1] = tmp; 
		--pos1;
	}
	while(pos2<j && ratings[pos2+1]>=ratings[pos2]){
		int tmp = dp[pos2] + ((ratings[pos2]==ratings[pos2+1])?0:1);
		if(dp[pos2+1]<tmp) dp[pos2+1] = tmp;
		++pos2;
	}
	if(pos1>i) inner_candy(ratings,i,pos1);
	if(pos2<j) inner_candy(ratings,pos2,j);
}

int Solution::get_min_pos(vector<int> &vec,int i,int j){
	int pos = i;
	int m = 1<<30;
	for(int k=i;k<=j;++k){
		if(vec.at(k)<m){
			m = vec.at(k);
			pos = k;
		}
	}
	return pos;
}