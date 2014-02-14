#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
		vector<int> tmp(digits);
		reverse(tmp.begin(),tmp.end());
        vector<int> vec;
        int N = tmp.size();
        int sum = 0;
        int i=0;
        for(;i<N && tmp[i]==9;i++){
            vec.push_back(0);
        }
        if(i==N){
            vec.push_back(1);
        }else{
            vec.push_back(1+tmp[i++]);
            for(;i<N;i++){
                vec.push_back(tmp[i]);
            }
        }
        reverse(vec.begin(),vec.end());
        return vec;
    }
};