#include <iostream>
#include <vector>
#include <string>

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
typedef pair<int, int> pii;
const  ll mod = 1e9 + 7;
ll gcd(ll a, ll b)  { return b ? gcd(b, a%b) : a; }
//head

void rightRotate(vector<string> &s){ //vector phải thêm & thì mới tham chiếu, khác với mảng nhé
    int n=s.size();
    vector<string> tmp(s);
    For(i,0,n)
        For(j,0,n)
            tmp[i][j]=s[n-1-j][i];
    //chép lại để cập nhật khi ra khỏi hàm
    For(i,0,n)
        For(j,0,n)
          s[i][j]=tmp[i][j];
}
int N, n;
int main()
{
    // đụ má khi nộp bài thì xóa giùm 2 cái dưới :'( chán vãi tèo
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (scanf("%d %d\n", &N, &n), N&&n){
		vector<string> S(N), s(n);
		For(i, 0, N) cin>>S[i];
        For(i, 0, n) cin>>s[i];
        For(r,0,4){
            int cnt = 0;
            For(i, 0, N - n + 1){
                For(j, 0, N - n + 1){
                    bool flag = 0;
                    For(k, 0, n)
                        For(l, 0, n)
                        if (s[k][l] != S[i + k][j + l]) {flag = 1; break;} //đáng lý break 2 For luôn
                    if (!flag) cnt++;
                }
            }
            rightRotate(s);
            printf("%d", cnt);
            if(r<3) printf(" ");
		}
		printf("\n");
	}

	return 0;
}
