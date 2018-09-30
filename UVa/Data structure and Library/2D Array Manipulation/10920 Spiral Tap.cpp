#include <bits/stdc++.h>
using namespace std;

#define For(i,a,n) for (int i=a; i<n; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define sz(x)  ((int)(x).size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;
const  ll mod = 1e9 + 7;
ll gcd(ll a, ll b)  { return b ? gcd(b, a%b) : a; }
//head
ll sz, p;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (scanf("%lld %lld\n", &sz, &p), sz&&p){
		ll root = sqrt(p);
		if (root % 2 == 0) root++;
		else if (p != root*root) root += 2;
		ll rightCorner = root*root;
		int i = root / 2, j = root / 2; //độ chênh
		if (root*root != 1){
			int side = (rightCorner - p) / (root - 1);
			switch (side){
			case 0: i -= rightCorner - p; break;
			case 1: {
					i *= -1;
					j -= rightCorner - (root - 1) - p;
					break;
			}
			case 2: {
						i = (-i) + rightCorner - 2 * (root - 1) - p;
						j *= -1;
						break;
			}
			case 3: j = (-j) + rightCorner - 3 * (root - 1) - p;
					break;
			}
		}
		printf("Line = %lld, column = %lld.\n", sz / 2 + i + 1, sz / 2 + j + 1);//đm chỗ này xuất ra long long ms chiệu :v vl
	}
	return 0;
}
