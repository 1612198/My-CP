//Y tuong: Tìm các CC của (x và @) và CC phải chứa ít nhất 1x,
//nằm theo kiểu chữ T thì mới được tính là còn sống

//kết hợp dfs + đếm số CC (numCC)
#include <bits/stdc++.h>
using namespace std;

int T,N;
char grid[105][105];

int dr[]={-1,0,1,0};  //chay theo chiu kim dong ho
int dc[]={0,1,0,-1};

void floodfill(int r,int c){  
	if(r<0||r>=N||c<0||c>=N ||grid[r][c]=='.') return ;
	grid[r][c]='.';
	for(int d=0;d<4;d++)
		floodfill(r+dr[d],c+dc[d]);
}

int main()
{
	// freopen("11953 in.txt","r",stdin);
	// freopen("11953 out.txt","w",stdout);

	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d",&N);
		for(int i=0;i<N;i++)
			scanf("%s",grid[i]);


		int ans=0;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(grid[i][j]=='x'){
					ans++;
					floodfill(i,j);
				}
			}
		}
		printf("Case %d: %d\n",t,ans);
	}

	return 0;
}