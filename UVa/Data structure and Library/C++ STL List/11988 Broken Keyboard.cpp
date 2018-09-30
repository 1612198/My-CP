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
string s;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	list<char> ans;
    list<char>::iterator it;
    while(cin>>s){
        ans.clear();
        it=ans.begin();
        For(i,0,s.length()-1){
            if(s[i]=='[') it=ans.begin();
            else if(s[i]==']') it=ans.end();
            else ans.insert(it,s[i]);
        }
        for(it=ans.begin();it!=ans.end();++it)
            printf("%c",*it);
        printf("\n");
    }

	return 0;
}
