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
int s,b;
const int N=1e5+5;
int Left[N],Right[N]; //Left, Right
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d %d\n",&s,&b), s||b){

        // với mối soldier gán vào vị trí 2 buddies và cập nhật thường xuyên
        For(i,1,s+1){
            Left[i]=i-1;
            Right[i]=i+1;
        }
        Left[1]=-1; // tương đương với * (ko có)
        Right[s]=-1;
        int l,r;
        For(i,0,b){
            scanf("%d %d\n",&l,&r);
            Right[Left[l]]=Right[r]; //update
            Left[Right[r]]=Left[l]; // couple new buddies is Le[l], Ri[r]
            if(Left[l]!=-1) printf("%d",Left[l]);
            else printf("*");
            if(Right[r]!=-1) printf(" %d\n",Right[r]);
            else printf(" *\n");
        }
        printf("-\n");
    }

	return 0;
}
