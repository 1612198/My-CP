#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n = 11;
	int a[] = {-7, 10, 9, 2, 3, 8, 8, 1, 2, 3, 4};
  	int L[n], L_id[n], T[n]; //L_id: L_index
  	int lis=0, lis_end=0;//tìm lis_end vì thằng T nó đâu có lưu end
  	for(int i=0;i<n;i++){
  		int pos=lower_bound(L,L+lis,a[i])-L;
  		//L[pos] >= a[i] nên a[i] phải thay thế L[pos]
  		//chuỗi con dài nhất kết thúc tại a[i] có lis=pos+1
  		L[pos]=a[i];
  		L_id[pos]=i;
  		T[i]=pos?L_id[pos-1]:-1; //lưu vị trí đứng liền trước
  		if(pos+1>=lis){  //co '=' nó mới ra greedy
  			lis=pos+1;
  			lis_end=i;
  		}
  	}
  	printf("LIS = %d\n",lis);
  	//Từ lis_end và bảng truy vết T ta suy ra solution
  	stack<int> sol;
  	int i=lis_end;
  	while(lis--){
  		sol.push(i);
  		i=T[i];
  	}
  	cout<<"The solution is: \n";
  	while(!sol.empty()){
  		cout<<a[sol.top()]<<" ";
  		sol.pop();
  	}

	return 0;
}