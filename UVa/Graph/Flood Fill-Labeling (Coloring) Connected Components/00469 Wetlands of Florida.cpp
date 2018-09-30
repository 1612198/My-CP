#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int dr[]={-1,-1,-1,0,1,1,1,0};  //1 vong tron 8 cells
int dc[]={-1,0,1,1,1,0,-1,-1}; 

int R,C;  //sizeof 2D array
vector<string> a;

int floodfill(int r,int c,char c1,char c2){
	if(r<0||r>=R || c<0 ||c>=C) return 0;
	if(a[r][c]!=c1) return 0;
	int ans=1;
	a[r][c]=c2;
	for(int d=0;d<8;d++){
		ans+=floodfill(r+dr[d],c+dc[d],c1,c2);
	}
	return ans;
}

int main()
{
	freopen("00469 in.txt","r",stdin);
	freopen("00469 out.txt","w",stdout);

	int T;
	scanf("%d\n\n",&T);
	while(T--){
		a.clear();
		string line;
		vector<ii> cell;
		cell.clear();
		while(getline(cin,line) &&!line.empty()){
			if(line[1]==' '||line[2]==' '){
				stringstream ss;
				ss.clear();
				ss<<line;
				int i,j;
				ss>>i>>j;
				cell.push_back(ii(i,j));
			}
			else a.push_back(line);
		}
	
		R=a.size(); C=a[0].length();
		vector<string> copyOfa(a);
		for(int i=0;i<cell.size();i++){
			printf("%d\n",floodfill(cell[i].first-1,cell[i].second-1,'W','.'));
			a=copyOfa;
		}
		if(T) printf("\n");
	}


	return 0;
}