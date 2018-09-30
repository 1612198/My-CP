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
typedef pair<int,int> pii;
const  ll mod = 1e9+7;
ll gcd(ll a, ll b)  {return b?gcd(b,a%b):a;}
//head
const int N=1e5+5;
vi v;
int tmp;
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
    while(scanf("%d\n",&tmp)!=EOF){
        v.pb(tmp);
        int n=v.size()/2;
        nth_element(v.begin(),v.begin()+n,v.end());
        ll res=v[n];
        if(v.size()%2==0){
            n--;
            nth_element(v.begin(),v.begin()+n,v.end()); //sắp xếp thêm vị trí trước trung vị đã có nữa
            res=(res+v[n])/2;
        }
        printf("%d\n",res);
    }

	return 0;
}
