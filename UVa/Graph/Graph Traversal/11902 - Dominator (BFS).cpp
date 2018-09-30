#include <bits/stdc++.h>
using namespace std;

const int INF=1e9;

int T,n,adjMat[100][100];
bool visited[100];
void bfs(int s){  //đỉnh nào đã duyệt nghĩa là visited[đỉnh đó]=true;
	queue<int> q;
	q.push(s);
	// vector<int> d(n,INF);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int j=0;j<n;j++){
			if((adjMat[u][j]!=0 || u==j) &&!visited[j]){  //connected hoặc chính nó và chưa được thăm
				visited[j]=true;
				// d[j]=d[u]+1;
				q.push(j);
			}
		}
	}
}

void printLine(){
	printf("+");
	for(int i=1;i<2*n;i++)
		printf("-");
	printf("+\n");
}

int main()
{
	// freopen("11902 in.txt","r",stdin);
	// freopen("11902 out.txt","w",stdout);
	scanf("%d",&T);
	for(int c=1;c<=T;c++){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&adjMat[i][j]);

		bool dominates[100][100];
		memset(dominates,0,sizeof dominates);
		dominates[0][0]=1;
		//remove_node: xét từng node có là dominate của những node nào
		for(int remove_node=1;remove_node<n;remove_node++){
			dominates[0][remove_node]=true;
			memset(visited,0,sizeof visited);
			visited[remove_node]=true;
			bfs(0);
			for(int i=0;i<n;i++)
				if(!visited[i])
					dominates[remove_node][i]=true;
			dominates[remove_node][remove_node]=true;
		}
		memset(visited,0,sizeof visited);
		bfs(0);
		printf("Case %d:\n",c);
		for(int i=0;i<n;i++){
			printLine();
			for(int j=0;j<n;j++){
				printf(dominates[i][j]&&visited[j]?"|Y":"|N"); //chỗ này hay nè, đưọc đưa phép toán 3 ngôi trong printf
			}
			printf("|\n");
		}
		printLine();
	}

	return 0;
}