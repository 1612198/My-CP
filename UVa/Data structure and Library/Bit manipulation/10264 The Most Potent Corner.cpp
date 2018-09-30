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
int N;
int corn[100000]; //2^15=32768
int sum[100000]; //tinh tong cac neighbor
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
    while(scanf("%d",&N)!=EOF){
        int num_corn=pow(2,N);
        //cerr<<num_corn<<endl;
        For(i,0,num_corn-1)
            scanf("%d",corn+i);
        For(i,0,num_corn-1){
            int sum_neighbor=0;
            For(j,0,N-1){
                int b=i^(1<<j);
                sum_neighbor+=corn[b];
            }
            sum[i]=sum_neighbor;
        }
        int ans=0;
        For(i,0,num_corn-1){
            For(j,0,N-1){
                int b=i^(1<<j);
                ans=max(ans,sum[i]+sum[b]);
            }
        }
        printf("%d\n",ans);
    }
	return 0;
}
