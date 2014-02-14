//û�����
class Solution {
public:
    int search(int A[], int n, int target) {
        if(n<1) return -1;
        int low = 0,up = n - 1,mid;
        while(low<=up){
            mid = (low+up)/2;
            if(A[mid]==target) return mid;
            else if(A[mid]>target){
				//mid���ڽϴ�ֵ����
                if(A[mid]>A[low]){	
					up = mid - 1;
				}else{
					if(A[up]>=target) low = mid + 1;
					else if(A[low]<=target) up = mid - 1;
					else return -1;
				}
            }else{  //A[mid]<target
				//mid���ڽ�Сֵ������
				if(A[mid]<=A[low]){
					if(A[low]<=target) up = mid - 1;
					else if(A[up]>=target) low = mid + 1;
					else return -1;
				}else{
					low = mid + 1;
				}
            }
        }
        return -1;
    }
};
