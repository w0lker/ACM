
/**
���ɿ��ؼ��ϵ�ȫ����
DFS+����
ȡ��ͨ1��n��ȫ���в�ͬ�����ؼ�������Ҫע�⣺
1����ÿ��λ��ͬ����Ԫ��ֻ���԰���һ������ {1,1,2,3,3,3}�ڵ�һλֻ��3�����1,2,3
2���ж�ĳ��λ���Ƿ���ʹ��ĳһԪ��Ҫ�����Ԫ���Ѿ���ʹ�ö��ٴ��ˣ�����ǰ4λ��1,3,1,3��ʱ��5λ�Ͳ�����1�ˣ�
	��ǰ4λ��1,2,3,3��ʱ��5λ����ʹ��1���ڳ�����ʹ��c1 c2����ʾԪ���ѱ�ʹ�ô������ڼ����г��ֵ��ܴ�����
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
			//Ҳ���Լ���һ���жϣ� if(num[i]!=num[i-1])�����Ͳ���ҪuniNum������
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
		//����ÿ��Ԫ��ֻ����һ�εļ���
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