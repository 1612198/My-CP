#include <iostream>
#include <vector>
 
using namespace std;
 
const int N =5e3 + 2;
int main()
{
 
	int a[N];
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	a[0] = -1e5;
	a[n + 1] = 1e5;
	vector<int> L(n + 2);
	/*vector<int> T(n + 1);*/
 
	L[n + 1] = 1;
	for (int i = n; i >= 0; i--){
		int jmax = 0;
		for (int j = i + 1; j <= n + 1; j++){
			if (a[j]>a[i] && L[j]>L[jmax]) { jmax = j; /*T[i] = jmax;*/ }
		}
		L[i] = L[jmax] + 1;
	}
 
	cout << L[0]-2<<endl;
	/*int i = 0;
	while (T[i] <= n){
		cout << a[T[i]] << "  ";
		i = T[i];
	}
*/
 
	return 0;
}