#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
using namespace std;

#define For(i,a,b) for (int i=a; i<=b; i++)
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

struct contestant{
	int cont;
	int num, pen, sub[10]; //number of problem, penalty time, number of submit on problem i
};
int n;
char s[100];
int c, p, t;
char L;

void init(vector<contestant> v ){
	For(i, 1, 100){
		v[i].cont = 0; //contestant
		v[i].num = 0;
		v[i].pen = 0;
		For(j, 1, 9)
			v[i].sub[j] = 0;
	}
}
bool comp(contestant A, contestant B){
	if (A.num<B.num) return true;
	if (A.num == B.num){
		if (A.pen > B.pen) return true;
		if (A.pen == B.pen) return A.cont>B.cont;
		return false;
	}
	return false;
}


int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &n);
	getchar();
	getchar();
	while (n--){
		vector<contestant> v(101);
		init(v);
		vector<contestant> ans;
		while (gets(s) && strlen(s)){
			sscanf(s, "%d%d%d %c", &c, &p, &t, &L);
			//cerr << c << p << t << L << endl;
			v[c].cont = c;
			if (L == 'I' && v[c].sub[p]!=-1) v[c].sub[p]++;
			if (L == 'C' && v[c].sub[p]!=-1) { v[c].num++; v[c].pen += t + 20 * v[c].sub[p]; v[c].sub[p]=-1; }
		}
		For(i, 1, 100){
			if (v[i].cont) ans.pb(v[i]);
		}
		sort(ans.begin(), ans.end(), comp);
		for (int i = ans.size() - 1; i >= 0;i--){
			printf("%d %d %d\n", ans[i].cont, ans[i].num, ans[i].pen);
		}
		if(n) printf("\n");
	}
	return 0;
}












