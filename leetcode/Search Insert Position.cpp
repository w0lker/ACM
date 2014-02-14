//���Ǹ����ˣ�
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

///��ʵֱ�����ö��ַ�����low�Ϳ�����
//���һ��low,up��Ȼָ��ͬһ������������targetֱ�ӷ���
//������target��low = low +1�պ�ΪӦ�ò����λ��
//��С��taget �� up = up - 1��low���䣬Ҳ������Ӧ�ò����λ�á�
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