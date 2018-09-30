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
        bitset<32> nn(n);
        bitset<32> a,b;
        a.reset(); b.reset();
        For(i,0,31){
            while(!nn[i]&&i<32) i++;
            if(i<32) a.set(i);
            i++;
            while(!nn[i]&&i<32) i++;
            if(i<32) b.set(i);
        }
        printf("%d %d\n",a.to_ulong(),b.to_ulong());
    }


	return 0;
}
