#include <bits/stdc++.h>
using namespace std;

int main()
{
	int m,n;
	int a[103][103];
	int b[103][103];
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++)
		for(int j=1; j<=n; j++)
			scanf("%d",&a[i][j]);

	for(int i=1;i<=m;i++)
		b[i][1]=a[i][1];
	//chen hang 0, m+1 cua matrix B = min
	for(int j=0;j<=n;j++){ 
		b[0][j]=-10001; //-100 * 100
		b[m+1][j]=-10001;
	}
	for(int j=2;j<=n;j++){
		for(int i=1; i<=m; i++){
			b[i][j]=a[i][j]+max(max(b[i-1][j-1],b[i][j-1]),b[i+1][j-1]);
		}
	}
	int maxn=b[1][n];
	for(int i=2;i<=m;i++)
		if(b[i][n]>maxn) maxn=b[i][n];
	printf("%d",maxn);
	return 0;
}