//方法2：使用变型的二分查找
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> vec(2,-1);
		if(n<1) return vec;
        int low = 0,up = n-1,mid;
		while(low<up){
			mid = (low+up)/2;
			if(A[mid]<target) low = mid + 1;
			else up = mid;
		}
		if(A[low]!=target) return vec;
		vec[0] = low;
		up = n-1;
		while(low<up){
			mid = (low+up)/2;
			if(A[mid]>target) up = mid;
			else low = mid+1;
		}
		vec[1] = up - 1;
        return vec;
    }
};

//方法1： 递归使用二分查找
class Solution {
    void bs(int A[],int target,int start,int end,int &low_bound,int &up_bound){
        int low = start,up = end,mid;
        low_bound = -1;
        up_bound = -1;
        while(low<=up){
            mid = (low+up)/2;
            if(A[mid]==target){
                int lb,ub;
                int lb2,ub2;
                low_bound = up_bound = mid;
                bs(A,target,start,mid-1,lb,ub);
                bs(A,target,mid+1,end,lb2,ub2);
                if(lb!=-1) low_bound = lb;
                if(ub2!=-1) up_bound = ub2;
                return;
            }else if(target<A[mid]) up = mid - 1;
            else    low = mid + 1;
        }
    }
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> vec(2,-1);
		if(n<1) return;
        bs(A,target,0,n-1,vec[0],vec[1]);
        return vec;
    }
};