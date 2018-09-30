#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{	
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	ll N,L,U;
	while(scanf("%lld%lld%lld",&N,&L,&U)!=EOF){
		ll M=0;  //M!=L bởi vì lúc nó bật bit thì đã > L rồi cần gì mấy bit sau của L
		for(int i=31;i>=0;i--){
			ll state=N&(1L<<i);
			if(state==0){ //bit i OFF !(N&(1L<<i))
				if(M+(1L<<i) <= U){
					M+=(1L<<i);
				}
			}
			else{ //ON //tại đây không bật thì sau này bật hết cũng chả lơn
				       //vì ta chạy trái sang nên nếu lúc này là bit M=0 & bit L=1
					   // các bit trước giống nhau.
				ll tmp=state-1; //thử bật tất cả bit sau đó rồi so sánh, nếu ko = nổi (tức là <) thì phải mở bit i thôi
				tmp+=M; //or tmp|=M; vì set bit M từ trái sang
				if(tmp<L){
					M+=(1L<<i); //bat bit i len
				}
			}
		}
		printf("%lld\n",M);
	}

	return 0;
}

