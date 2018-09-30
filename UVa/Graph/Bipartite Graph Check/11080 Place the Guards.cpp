//11080 Place the Gurards
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int INF=1e7;

int T,v,e;
vector<vi> adjList;
vi color;
int BiGcheck(int source, int firstColor){
	// color.assign(202,INF);

	queue<int> q;
	q.push(source); //push vào cái giao lộ 0
	color[source]=firstColor;  //1: has guard, 0: no guard
	cerr<<"0 mau "<<firstColor<<endl;
	bool isBipartite=true;
	int cnt=firstColor;
	while(!q.empty()&&isBipartite){
		int u=q.front();
		q.pop();
		for(int i=0;i<adjList[u].size();i++){
			int v=adjList[u][i];
			if(color[v]==INF){
				cerr<<v<<" mau "<<1-color[u]<<"\n";
				color[v]=1-color[u];
				cnt+=color[v];
				q.push(v);
			}
			else 
				if(color[v]==color[u]){
					isBipartite=false;
					break;
				}
		}
	}
	if(!isBipartite) return -1;
	// int cnt=0;
	// for(int i=source;i<v;i++){
	// 	if(color[i]==1) cnt++;
	// }
	cerr<<"trong ham cnt = "<<cnt<<endl;
	if(cnt==0) cnt=1; //1 ngã tư thì có ít nhất 1 guard đứng
	return cnt;
}

void xuat(){
	for(int i=0;i<v;i++){
		cerr<<i;
		for(int j=0;j<adjList[i].size();j++){
			cerr<<"-"<<adjList[i][j];
		}
		cerr<<endl;
	}
}
int main()
{
	freopen("11080 in.txt","r",stdin);
	freopen("11080 out.txt","w",stdout);

	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&v,&e);
		adjList.assign(202,vi(0));
		int dau, cuoi;
		while(e--){
			scanf("%d%d",&dau,&cuoi);
			adjList[dau].push_back(cuoi);
			adjList[cuoi].push_back(dau);
		}
		xuat();
		int cnt=0;
		color.assign(202,INF);
		vi tmp;
		int x,y;
		for(int i=0;i<v;i++){
			if(color[i]==INF) {
				tmp=color;
				x=BiGcheck(i,0);  //cac sub-graph doc lap
				color=tmp;
				y=BiGcheck(i,1);  //du x hay y thi sub-graph vẫn chưa all !=iNF
				if(x==-1 && y==-1) {
					cnt=-1;
					break;
				}
				else {
					if(x==-1) cnt+=y;
					else if(y==-1) cnt+=x;
					else { //1 ngã tu mà ko ai đứng là ko đưọc
						cnt+=min(x,y);
					}
				}
			}

		}
		if(cnt==-1) printf("-1\n");
		else printf("%d\n",cnt);
	}


	return 0;
}