#include <iostream>
#include <set>
using namespace std;

int main()
{
	//constructor from array
	int arr[]={10,20,30,50,40};
	set<int> s(arr,arr+5);
	//access element
	for(auto x:s) 
		cout<<x<<" ";
	cout<<endl;
	//array dump into set s: s automatically sort ascending and filter elements overlap
	
	//* Some methods of class set
	//Thêm phần tử
	s.insert(15);
	for(auto x:s) 
		cout<<x<<" ";
	cout<<endl;
	//Xóa phần tử
	s.erase(10);
	for(auto x:s) 
		cout<<x<<" ";
	cout<<endl;
	//check 1 phần tử đã có trong set hay chưa
	cout<<s.count(100)<<endl;	
	//s.count(int) return 0 or 1

	//size of set
	cout<<s.size()<<endl;

	return 0;
}