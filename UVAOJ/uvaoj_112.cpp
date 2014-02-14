#include <string>
#include <iostream>

using namespace std;

string expr;
int tar_sum;

bool read(int sum,int tar,bool *emp){
	bool rst = false;
	char bracket;
	cin>>bracket;
	int num;
	bool emp_l=false;
	bool emp_r=false;
	*emp=(cin>>num)==0;
	if(!*emp){		//非空
		sum+=num;
		rst = read(sum,tar,&emp_l) || read(sum,tar,&emp_r);
	}
	if(emp_l && emp_r) rst = (sum==tar); 
	cin.clear();
	cin>>bracket;
	return rst;
}

int main_112(){
	bool emp_flag;
	while(cin>>tar_sum){
		cout<<(read(0,tar_sum,&emp_flag)?"yes":"no")<<endl;
	//	bool bl = read(0,tar_sum,&emp_flag);
		//cout<<bl<<endl;
	}
	//for (int nDest; cin >> nDest;) {
 //       //根据结果输出yes或no
 //       cout << (read(0,tar_sum,&emp_flag) ? "yes" : "no") << endl;
 //   }

	return 0;
}


