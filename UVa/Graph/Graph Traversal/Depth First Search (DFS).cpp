#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vi dfs_num;//global variable, initially all values are set to UNVISITED
void dfs(int u){
	dfs_num[u]=VISITED;
	for(int j=0;j<(in)adjList[u].size();j++){
		ii v=adjList[u][j];
		if (dfs_num[v.first]==UNVISITED)
			dfs(v.first);
	}
}

//dfs doi voi adjacency Matrix.
void dfs_mat(int u){
	visited[u]=true;
	for(int i=0;i<n;i++)
		if(mat[u][i]!=0 && !visited[i])
			dfs(i);
}


//dfs using stack
int sets=0;
    for(int i = 0; i < size; i++)
    {
      if(!visited[i])
      {
		sets++;
		stack<int> S;
		S.push(i);
		while(S.size())
		{
		  int src = S.top();
		  S.pop();
		  for(int j = 0; j < edges[src].size(); j++)
		  {
		    int dest = edges[src][j];
		    if(!visited[dest])
		    {
		      visited[dest] = true;
		      S.push(dest);  //thăm nó ròi push vô stack để lấy ra duyệt sâu xuống nhánh của nó.
		    }
		  }
		}
      }
    }
    cout << sets << endl;

int main()
{


	return 0;
}