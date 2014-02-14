//考虑复杂了，
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
		if(n<1) return 0;
        int low = 0;
        int up = n-1;
        int mid;
        while(low<=up){
            mid = (low+up)/2;
            if(A[mid]==target){
                return mid;
            }else{
                if(low==up){
                    if(A[mid]>target) return mid;
                    else    return mid + 1;
                }else{
                    if(A[mid]>target){
                        up = mid - 1;
                    }else low = mid + 1;
                }
            }
        }
    }
};

///其实直接利用二分法返回low就可以了
//最后一次low,up必然指向同一个数，若等于target直接返回
//若大于target则low = low +1刚好为应该插入的位置
//若小于taget 则 up = up - 1，low不变，也正好是应该插入的位置。
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
		if(n<1) return 0;
        int low = 0;
        int up = n-1;
        int mid;
        while(low<=up){
            mid = (low+up)/2;
            if(target==A[mid]){
                return mid;
            }else if(target<A[mid])
                up = mid - 1;
            else 
				low = mid + 1;
        }
		return low;
    }
};