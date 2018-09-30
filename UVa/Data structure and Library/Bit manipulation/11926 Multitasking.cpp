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
int n,m;
int start,endi,loop;
 bitset<1000000> minute;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

    while(scanf("%d %d",&n,&m),n||m){
        bool conflict=false;
        minute.reset();
        For(i,1,n){
            scanf("%d %d",&start,&endi);
            For(j,start,endi-1) {
                if(minute[j]==1){
                    conflict=true;
                    break;
                }
                else minute.set(j);
            }
        }
        For(i,1,m){
            scanf("%d %d %d",&start,&endi,&loop);
            while(start<1000000){
                For(j,start,endi-1){
                    if(minute[j]) {conflict=true; break;}
                    else minute.set(j);
                }
                start+=loop;
                endi=min(endi+loop,1000000);
            }
        }
        if(conflict) printf("CONFLICT\n");
        else printf("NO CONFLICT\n");
    }
	return 0;
}
