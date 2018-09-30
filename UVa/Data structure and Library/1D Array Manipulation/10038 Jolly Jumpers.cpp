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
    const  ll mod = 1000000007;
    ll gcd(ll a, ll b)  {return b?gcd(b,a%b):a;}
    //head
    const int N =3003;
    int n;
    int a[N];
     // calculate from 1 to n-1
    int flag[N]={0};

    bool find(int arr[],int x,int y, int k){
        for(int i=x;i<=y; i++){
            if(arr[i]==k) return true;
        }
        return false;
    }
    int main()
    {
        while(scanf("%d",&n)!=EOF){
                For(i,0,n) scanf("%d",a+i);
                For(i,1,n){
                    int dif=abs(a[i]-a[i-1]);
                    if(0<dif && dif<n) flag[dif]=1;
                }
                if(find(flag,1,n-1,0)){
                    cout<<"Not jolly"<<endl;
                }
                else cout<<"Jolly"<<endl;
                For(i,1,n) flag[i]=0;
        }
        return 0;
    }
