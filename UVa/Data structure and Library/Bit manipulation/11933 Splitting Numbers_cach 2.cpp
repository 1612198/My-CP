#include <bits/stdc++.h>
using namespace std;

#define For(i,a,b) for (int i=a; i<=b; i++) //have =
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
int n;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
    while(scanf("%d",&n),n){
        int a=0,b=0;
        int i=0;
        bool A=true;
        while(n>0){
            if(1&n){  //get bit
              if(A) {a|=1<<i; A=false;}  //set bit
              else {b|=1<<i; A=true;}
            }
            n=n>>1;
            i++;
        }
        printf("%d %d\n",a,b);
    }
	return 0;
}
