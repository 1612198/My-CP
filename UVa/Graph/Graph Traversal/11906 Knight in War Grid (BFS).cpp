#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int T,R,C,M,N,W;
int mat[100+2][100+2];

int main()
{
	freopen("11906 in.txt","r",stdin);
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		memset(mat,0,sizeof mat);
		scanf("%d%d%d%d",&R,&C,&M,&N);
		scanf("%d",&W);
		map<ii,bool> waterMap; //water map
		for(int i=0;i<W;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			waterMap[ii(a,b)]=true; //Không gán = true(1) thì mặc định là false (0).
		}
		queue <ii> q;
		q.push(ii(0,0));
		map<ii,bool> visited;
		visited[ii(0,0)]=true;
		mat[0][0]=0;
		int dr[]={-M,-M,M,M,-N,N,-N,N};
		int dc[]={N,-N,N,-N,M,M,-M,-M};
		while(!q.empty()){
			ii pop=q.front();
			q.pop();
			int newX,newY;
			set<ii> distinct;
			for(int i=0;i<8;i++){
				newX=dr[i]+pop.first;
				newY=dc[i]+pop.second;
				distinct.insert(ii(newX,newY));
			}
			for(set<ii>::iterator it=distinct.begin();it!=distinct.end();it++){
				pop=*it;
				newX=pop.first;
				newY=pop.second;
				if(newX>=0 && newX<R &&newY>=0&&newY<C &&!waterMap[ii(newX,newY)]){
					mat[newX][newY]++;
					if(!visited[ii(newX,newY)]){ //chi de push vao queue thoi
						visited[ii(newX,newY)]=true;
						q.push(ii(newX,newY));
					}
				}
			}
		}
		int cntEven=0,cntOdd=0;
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				if(mat[i][j]||(!i&&!j)){
					if(mat[i][j]%2) cntOdd++;
					else cntEven++;
				}
			}
		}
		printf("Case %d: %d %d\n",t,cntEven,cntOdd);

	}

	return 0;
}