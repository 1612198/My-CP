//inside int main()
queue<int> q;
q.push(s);
vi color(V,INF);  //initial all nodes aren't painted 
bool isBipartite=true;
while(!q.empty()&&isBipartite){
	int u=q.front();
	q.pop();
	for(int j=0;j<(int)AdjList[u].size();j++){
		ii v=AdjList[u][j];
		if(color[v.first]==INF){
			color[v.first]=1-color[u];
			q.push(v.first);  //push  là coi như thăm á
		}
		else if(color[v.first]==color[u]){
			isBipartite=false; //cần vì có khi trúng cái cuối nó trùng màu, lúc đó queue cũng empty mà.
			break;  //cần chứ break cái for mà, false sẽ break while()
		}
	}
}
