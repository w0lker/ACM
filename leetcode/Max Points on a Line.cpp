/**
˼·��
����ÿ����i�����������е�j�������б�ʣ�б����ͬ�ĵ���һ��ֱ���ϡ�������б��Ϊ������map�洢
i�ڲ�ѭ��ʱ��ֻ��Ҫ���������ĵ㼴�ɣ���Ϊ����С�ĵ��Ѿ��ڼ��� ��(j,i)���ߵĵ���ʱ������ˡ�
������Դ��www.cnblogs.com/TenosDoIt/p/3444086.html
**/

#include <vector>
#include <unordered_map>
#include <limits>
#include <algorithm>

using namespace std;

 struct Point {
	 int x;
	 int y;
	 Point() : x(0), y(0) {}
	 Point(int a, int b) : x(a), y(b) {}
 };
 
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int res = 1;
		int n = points.size();
		if(n<3) return n;
		for(int i=0;i<n;++i){
			int tmp_res = 1;
			int same_points = 0;
			unordered_map<double,int> m;
			for(int j=i+1;j<n;++j){
				int tmp = 0;
				double slope = std::numeric_limits<double>::infinity();
				if(points[i].x==points[j].x){
					if(points[i].y==points[j].y){
						same_points++;
						continue;
					}
				} else 	slope = (points[i].y-points[j].y)/(double)(points[i].x-points[j].x);
				if(m.find(slope)!=m.end()){
					tmp = ++m[slope];
				}else{
					m.insert(make_pair(slope,2));
					tmp = 2;
				}
				tmp_res = max(tmp_res,tmp);
			}
			res = max(res,tmp_res+same_points);
		}
		
		return res;
    }
};