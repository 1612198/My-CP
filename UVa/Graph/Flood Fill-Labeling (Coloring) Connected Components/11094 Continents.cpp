#include <bits/stdc++.h>
using namespace std;

int R,C,x,y;
char grid[25][25];

// int dr[]={-1,-1,-1,0,1,1,1,0};
// int dc[]={-1,0,1,1,1,0,-1,-1};

int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};

int floodfill(int r,int c,char c1,char c2){
	if(r<0||r>=R) return 0;
	if(c<0) c=C-1;
	if(c==C) c=0;
	if(grid[r][c]!=c1) return 0;
	int ans=1;
	grid[r][c]=c2;
	for(int i=0;i<4;i++){
		ans+=floodfill(r+dr[i],c+dc[i],c1,c2);
	}
	return ans;
}
int main()
{
	// freopen("11094 in.txt","r",stdin);
	// freopen("11094 out.txt","w",stdout);

	while(scanf("%d%d\n",&R,&C)!=EOF){
		for(int i=0;i<R;i++){
			for(int j=0;j<=C;j++)  //=c để nó get \n vào trong kí tự cuối
				scanf("%c",&grid[i][j]);
		}
		
		scanf("%d%d",&x,&y);
		char c1=grid[x][y];  //nó đứng chỗ nào chứng tỏ chỗ đó là land, chỗ khác nó là water
		floodfill(x,y,c1,c1+1);
		int ans=-1;
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++)
				ans=max(ans,floodfill(i,j,c1,c1+1));
		}
		printf("%d\n",ans);
	}


	return 0;
}