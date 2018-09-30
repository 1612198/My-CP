#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 11;
	// int a[] = {-7, 10, 9, 2, 3, 8, 8, 1, 2, 3, 4};
	int a[]={1,1,1,1,1,1,1,1,1,1,1};
	//answer is 5: -7 < 1 < 2 < 3 < 4
	int LIS[n];
	LIS[0]=1;
	int T[n];
	for(int i=1;i<n;i++){
		int maxj=0,idx; //maxj=0 vì ít ra nó đứng 1 mình là maxj+1=1 chứ
		for(int j=0;j<i;j++){
			if(LIS[j]>maxj && a[j]<a[i]) maxj=LIS[j],idx=j;
		}
		LIS[i]=maxj+1;
		T[i]=idx;  //LIS tai i có phần tử liền trước là a[T[i]]
	}
	for(int i=0;i<n;i++){
		printf("%d ",LIS[i]);
	}
	cout<<endl;
	int ans=-1;
	int last_idx=0;
	for(int i=0;i<n;i++)
		if(LIS[i]>ans){
			ans=LIS[i];
			last_idx=i;  //lưu lại last_idx vi T[i] la lưu liền trước nên ko có lưu cái cuối
		}
	// cout<<"Last_idx = "<<last_idx<<endl;
	printf("Longest Increasing Subsequence has size = %d\n",ans);
	printf("Solution: \n");  //Từ last_idx + T[] => solution
	int i=last_idx;
	vector<int> solution;
	while(ans--){ //bao nhiêu cái thì in ra bấy nhiu thôi
		// cerr<<a[i]<<" ";  //đảo ngược lại cho nó đẹp thôi
		solution.push_back(a[i]);
		i=T[i];
	}
	for(int i=solution.size()-1;i>=0;i--)
		printf("%d ",solution[i]);
	


	return 0;
}