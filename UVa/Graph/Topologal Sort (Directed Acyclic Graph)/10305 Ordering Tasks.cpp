#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int n,m;  //n<100
vector<vi> adjList;
vector<bool> visited;
vector<int> tpOrder;

void dfs2(int u){
	visited[u]=true;
	for(int i=0;i<adjList[u].size();i++){
		int v=adjList[u][i];
		if(!visited[v]){
			dfs2(v);
		}
	}
	tpOrder.push_back(u);
}
// void xuat(){
// 	for(int i=1;i<=n;i++){
// 		for(int j=0;j<adjList[i].size();j++)
// 			cerr<<adjList[i][j]<<" ";
// 		cerr<<endl;
// 	}

// }

int main()
{
	// freopen("10305 in.txt","r",stdin);
	// freopen("10305 out.txt","w",stdout);


	while(scanf("%d%d",&n,&m),n||m){
		adjList.assign(104,vi(0));
		visited.assign(104,false);
		tpOrder.clear();

		int a,b;
		for(int i=0;i<m;i++){
			scanf("%d%d",&a,&b);
			adjList[a].push_back(b);
		}
		// xuat();

		for(int node=1;node<=n;node++){
			if(!visited[node]){
				dfs2(node);
			}
		}
		//reverse tpOrder
		for(int i=n-1;i>=0;i--){
			printf("%d",tpOrder[i]);
			printf(i>0?" ":"\n");
		}

	}

	return 0;
}