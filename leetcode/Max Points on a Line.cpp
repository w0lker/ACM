/**
思路：
对于每个点i，把其他所有点j和其计算斜率，斜率相同的点在一条直线上。可以以斜率为索引用map存储
i内部循环时，只需要计算比他大的点即可，因为比他小的点已经在计算 和(j,i)共线的点数时计算过了。
代码来源：www.cnblogs.com/TenosDoIt/p/3444086.html
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