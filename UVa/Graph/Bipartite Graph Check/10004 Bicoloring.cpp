#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
const int INF = 1e7;

int n,l;
vector<vi> adjList;

int main()
{
	// freopen("10004 in.txt","r",stdin);
	// freopen("10004 out.txt","w",stdout);
	while(scanf("%d",&n),n){
		scanf("%d",&l);
		adjList.assign(202,vi(0));
		int dau,cuoi;

		while(l--){
			scanf("%d%d",&dau,&cuoi);
			adjList[dau].push_back(cuoi);
			adjList[cuoi].push_back(dau);
		}
		queue<int> q;
		vector<int> color(202,INF);
		q.push(0);
		color[0]=0;
		bool isBipartite=true;
		while(!q.empty() && isBipartite){
			int u=q.front();
			q.pop();
			for(int i=0;i<adjList[u].size();i++){
				int v=adjList[u][i];
				if(color[v]==INF){
					color[v]=1-color[u];
					q.push(v);
				}
				else if(color[v]==color[u]){
					isBipartite=false;
					break;
				}
			}
		}
		if(isBipartite) printf("BICOLORABLE.\n");
		else printf("NOT BICOLORABLE.\n");
	}

	return 0;
}