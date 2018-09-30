/*
	Three ways:
	1. Adjacency Matrix
	2. Adjacency List
	3. Edge List
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

int main()
{
	int V,E,total_neighbors,id,weight,a,b;
	int adjMat[100][100];
	vector<vii> adjList;
	priority_queue<pair<int,ii>> EdgeList;
	freopen("Graph_Represent in.txt","r",stdin);
	scanf("%d",&V); //size of graph (number of vertices)
	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			scanf("%d",&adjMat[i][j]);

	printf("Neighbors of vertex 0:\n");
	for(int j=0;j<V;j++)
		if(adjMat[0][j])
			printf("Edge 0-%d (weight = %d)\n",j,adjMat[0][j]);

	scanf("%d",&V);
	adjList.assign(V,vii()); //adjList size=V and each element is vii()
	for(int i=0;i<V;i++){
		scanf("%d",&total_neighbors);
		for(int j=0;j<total_neighbors;j++){
			scanf("%d%d",&id,&weight);
			adjList[i].push_back(ii(id-1,weight)); //some index adjustment

		}
	}

	printf("Negihbors of vertex 0:\n");
	for(vii::iterator j=adjList[0].begin();j!=adjList[0].end();j++){
		printf("Edge 0-%d (weight = %d)\n",j->first,j->second);
	}
	scanf("%d",&E);
	for(int i=0;i<E;i++){
		scanf("%d %d %d",&a,&b,&weight);
		EdgeList.push(make_pair(-weight,ii(a,b)));
	}
	for(int i=0;i<E;i++){
		pair<int,ii> edge=EdgeList.top();
		EdgeList.pop();
		printf("weight: %d (%d-%d)\n:",-edge.first,edge.second.first,edge.second.second);
	}


	return 0;
}