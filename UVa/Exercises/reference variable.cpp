#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
	ll a=5;
	ll& b=a;
	cout<<b<<endl;
	if(&a==&b) cout<<"2 dia chi = nhau\n";
	cout<<"sizeof b="<<sizeof b<<endl;

	return 0;
}
/*
	ll& b=a; giống như việc truyền biến a vào hàm có đối số tham chiếu int&
	lúc đó: b giống như alias của a
	+ gía trị b= gía trị a
	+ địa chỉ b= địa chỉ của a
	+ kích thước của b = kích thước của a (ko nhất thiết là 4 bytes như con trỏ)
*/