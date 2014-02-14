
/**
生成可重集合的全排列
DFS+回溯
取普通1到n的全排列不同，可重集合中需要注意：
1、在每个位置同样的元素只可以安排一次例如 {1,1,2,3,3,3}在第一位只有3中情况1,2,3
2、判断某个位置是否能使用某一元素要看这个元素已经被使用多少次了，例如前4位是1,3,1,3此时第5位就不能用1了，
	若前4位是1,2,3,3此时第5位可以使用1，在程序中使用c1 c2来表示元素已被使用次数和在集合中出现的总次数。
**/
class Solution {
	vector<vector<int> > ans;
	int N;
	void dfs(vector<int> &path,vector<int> &num,vector<int> &uniNum){
		if(path.size()==N){
			ans.push_back(path);
			return;
		}
		for(int i=0;i<uniNum.size();++i){
			//也可以加上一个判断： if(num[i]!=num[i-1])这样就不需要uniNum数组了
			int c1 = 0,c2 = 0;	
			for(int j=0;j<path.size();++j){
				if(path[j]==uniNum[i]) c1++;
			}
			for(int j=0;j<num.size();++j){
				if(num[j]==uniNum[i]) c2++;
			}
			if(c1<c2){
				path.push_back(uniNum[i]);
				dfs(path,num,uniNum);
				path.pop_back();
			}
		}
	
	}
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        N = num.size();
		if(N==0) return ans;
		vector<int> vec;
		sort(num.begin(),num.end());
		//生成每个元素只出现一次的集合
		vector<int> uniNum;
		uniNum.push_back(num[0]);
		int pos = 0;
		for(int i=1;i<N;++i){
			if(num[i]!=uniNum[pos]){
				uniNum.push_back(num[i]);
				++pos;
			}
		}
		///////////////////
		dfs(vec,num,uniNum);
		return ans;
    }
};