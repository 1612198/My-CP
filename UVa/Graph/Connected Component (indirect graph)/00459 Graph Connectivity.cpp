#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vector<vi> adjList;
int visited[100]; //initial = 0
void dfs(int u){
	visited[u]=1;
	for(int i=0;i<adjList[u].size();i++){
		int v=adjList[u][i];
		if(!visited[v]) dfs(v);
	}
}

int main()
{
	// freopen("00459 in.txt","r",stdin);
	// freopen("00459 out.txt","w",stdout);
	int T;
	std::ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		char c;
		cin>>c;  //char not consume '\n' nên phải consume...
		int n=c-65;
		adjList.assign(100,vi(0));  //tạo n+2 element, mỗi cái là 1 vector<int> size 0
		string line;
		getline(cin,line); //consume the blank line

		while(1){
			getline(cin,line);
			// cout<<line<<endl;
			adjList[line[0]-65].push_back(line[1]-65);
			adjList[line[1]-65].push_back(line[0]-65);
			if(line.length()==0) break;
		}
		memset(visited,0,sizeof visited);
		int numCC=0;
		for(int i=0;i<=n;i++){
			if(!visited[i]){
				numCC++;
				dfs(i);
			}
		}
		printf("%d\n",numCC);
		if(T) printf("\n");
	}

	return 0;
}