//inside int main() ---no recursion
vi d(V,INF);
d[s]=0;  //distance from source s to s is 0
queue<int> q;  
q.push(s); //start from source
while(!q.emmpty()){
	int u=q.front();
	q.pop();
	for(int j=0;j<(int)adjList[u].size();j++){
		ii v=adjList[u][j];
		if (d[v.first]==INF){  //để push vào stack 
			d[v.first]=d[u]+1;
			q.push(v.first);
		}
	}
}

