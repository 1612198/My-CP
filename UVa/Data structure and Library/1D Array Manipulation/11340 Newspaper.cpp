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
int n;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d\n",&n);

    while(n--){
        int k;
        double tmp;
        char c;
        scanf("%d\n",&k);
        //cerr<<"k="<<k<<endl;
        double cost[260]={0.0};
        For(i,0,k) {
            scanf("%c %lf\n",&c,&tmp);
            cost[c+128]=tmp;  //because ascii from -128 to 127
        }
        double sum=0;
        int numLine;
        scanf("%d\n",&numLine);
        while(numLine--){
            string line;
            //cin.ignore(); already \n then need not ignore()
            getline(cin,line);
            For(i,0,line.length()){
                sum+=cost[line[i]+128];
            }
        }
        printf("%.2lf$\n",sum/100.0);
    }
	return 0;
}
/*
    nhớ ascii chạy từ -128 đến 127 nên phải cộng thêm 128
    float là 1 ví dụ
    scanf thêm \n để đúng form input thì khỏi ignore() khi chuyển từ int sang string
*/
