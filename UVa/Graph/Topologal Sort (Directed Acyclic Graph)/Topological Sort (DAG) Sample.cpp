#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vi ts;
int visited[100]={0};
vector<vi> adjList(8,vi(0));
void dfs2(int u){
	visited[u]=1;
	for(int j=0;j<adjList[u].size();j++){
		int v=adjList[u][j];
		if(!visited[v]) //v nhe'
			dfs2(v);
	}
	cerr<<"uuuu="<<u<<endl;
	ts.push_back(u);
}

void xuat(){
	for(int i=0;i<8;i++){
		cerr<<i<<" ";
		for(int j=0;j<adjList[i].size();j++)
			cerr<<adjList[i][j]<<" ";
		cerr<<endl;
	}
}


int main()
{
	adjList[0].push_back(1);
	adjList[0].push_back(2);
	adjList[1].push_back(2);
	adjList[1].push_back(3);
	adjList[2].push_back(3);
	adjList[2].push_back(5);
	adjList[3].push_back(4);
	adjList[7].push_back(6);

	// adjList[0].push_back(2);
	// adjList[0].push_back(1);
	// adjList[1].push_back(3);
	// adjList[1].push_back(2);
	// adjList[2].push_back(3);
	// adjList[2].push_back(5);
	// adjList[3].push_back(4);
	// adjList[7].push_back(6);

	xuat();
	// cerr<<adjList[3][2]<<"  ";
	memset(visited,0,sizeof visited);
	ts.clear();
	for(int i=0;i<8;i++)
		if(!visited[i]){
			dfs2(i);
		}
	printf("one of valid toposorts :\n"); //điều chỉnh thứ tự push_back ta được topo order như sách :v
	for(int i=ts.size()-1;i>=0;i--)
		printf("%d ",ts[i]);
	printf("\n");







	return 0;
}

//Kahn's Algorithm: https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
