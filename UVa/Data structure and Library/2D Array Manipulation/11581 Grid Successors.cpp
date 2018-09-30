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
int N;
vector<string> g(3);
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d\n",&N);
    string empLine;
    while(N--){
        For(i,0,3) cin>>g[i];
        //debug here
        //For(i,0,3) cerr<<g[i]<<endl;

        vector<string> hi(g);
        int cnt=0;
        For(i,0,3)
            For(j,0,3) if(g[i][j]=='0') cnt++;
        if(cnt==9) { printf("-1\n"); continue;}
        int index=0;
        while(index>=0){
            hi[0][0]=(g[0][1]+g[1][0])%2;
            hi[0][1]=(g[0][0]+g[0][2]+g[1][1])%2;
            hi[0][2]=(g[0][1]+g[1][2])%2;
            hi[1][0]=(g[0][0]+g[2][0]+g[1][1])%2;
            hi[1][1]=(g[0][1]+g[1][0]+g[1][2]+g[2][1])%2;
            hi[1][2]=(g[0][2]+g[1][1]+g[2][2])%2;
            hi[2][0]=(g[1][0]+g[2][1])%2;
            hi[2][1]=(g[1][1]+g[2][0]+g[2][2])%2;
            hi[2][2]=(g[1][2]+g[2][1])%2;
            cnt=0;
            For(i,0,3)
                For(j,0,3)
                    if(hi[i][j]==0) cnt++;
            if(cnt==9) break;
            g=hi;
            index++;
        }
        printf("%d\n",index);
    }
    return 0;
}
