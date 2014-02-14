//高效的二分解法

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int row = matrix.size();
		if(row==0) return false;
		int col = matrix[0].size();
        int low = 0;
		int up = row - 1;
		int mid;
		bool noExits = true;
		while(low<=up){
			mid = (low+up)/2;
			if(matrix[mid][0]<=target && matrix[mid][col-1]>=target){
				noExits = false;
				break;
			}else if(matrix[mid][0]>target){
				up = mid - 1;
			}else low = mid + 1;
		}
		if(noExits) return false;
		int r = mid;
		low = 0,up = col-1;
		while(low<=up){
			mid = (low+up)/2;
			if(matrix[r][mid]==target) return true;
			else if(matrix[r][mid]>target) up = mid - 1;
			else low = mid + 1;
		}
		return false;
    }
};

//AC的解法，但是效率不高
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int row = matrix.size();
		if(row==0) return false;
		int col = matrix[0].size();
        for(int r=0;r<row;++r){
            if(target<=matrix[r][col-1]){
                for(int c=0;c<col;++c){
                    if(target==matrix[r][c]) return true;
                }
                return false;
            }
        }
		return false;
    }
};

//无聊的做法，把matrix存到vector里
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        vector<int> shualai;
		int row = matrix.size();
		int col = matrix[0].size();
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                shualai.push_back(matrix[i][j]);
            }
        }
        return find(shualai.begin(),shualai.end(),target)!=shualai.end();
    }
};