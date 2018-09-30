#include <bits/stdc++.h>
using namespace std;

int count(int a){
	int cnt=0;
	while(a!=0){
		cnt++;
		a-=(a&(-a));  //chạy = tay ra sẽ rõ :v a&(-a) = a&(bù 1) +1
	}
	return cnt;
}
int  main()
{
	int a=7;
	cout<<count(a)<<endl;


	return 0;
}