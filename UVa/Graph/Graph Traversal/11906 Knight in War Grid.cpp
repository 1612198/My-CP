#include <bits/stdc++.h>
using namespace std;

#define MAX 102

int T,R,C,M,N;
int visit[MAX][MAX], g[MAX][MAX],cnt[MAX][MAX];

int incr[2]={1,-1};

void dfs(int x,int y){  //x: rows, y: cols
	if(visit[x][y]) return;
	visit[x][y]=1;  //xét tới nó là tăng 8 cái xung quanh nó
	int m,n;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			m=x+incr[i]*M;
			n=y+incr[j]*N;
			if(m>=0 && m<R && n>=0 && n<C &&g[m][n]!=-1){
				cnt[m][n]++;
				dfs(m,n);
			}
			m=x+incr[i]*N;
			n=y+incr[j]*M;
			if(m>=0 && m<R && n>=0 && n<C &&g[m][n]!=-1){
				cnt[m][n]++;
				dfs(m,n);
			}
		}
	}


}

int main()
{
	// freopen("11906 in.txt","r",stdin);
	// freopen("11906 out.txt","w",stdout);

	scanf("%d",&T);
	for(int c=1;c<=T;c++){
		scanf("%d%d%d%d",&R,&C,&M,&N);
		int W,x,y;
		scanf("%d",&W);
		memset(g,0,sizeof g);

		for(int i=0;i<W;i++) {
			scanf("%d%d",&x,&y);
			g[x][y]=-1;  //cells have water
		}
		memset(cnt,0,sizeof cnt);
		memset(visit,0,sizeof visit);
		int even=0,odd=0;
		dfs(0,0);
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				if(M==0||N==0||M==N){  //we counted twice
					cnt[i][j]/=2;
				}
				// cerr<<cnt[i][j]<<endl;
				if(cnt[i][j] ||(!i&&!j) ){ //TH mà cnt[0][0]=0, nghĩa là có mình nó đứng được thì có nghĩa là từ nó ko thể jump qua ô nào khác => cnt=0, chắn nên even=1; 
					if(cnt[i][j]%2==0) even++;
					else odd++;
				}
			}
		}
		printf("Case %d: %d %d\n",c,even,odd);


	}

	return 0;
}