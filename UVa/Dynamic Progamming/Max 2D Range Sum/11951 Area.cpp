#include <bits/stdc++.h>
using namespace std;



int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int c=1;c<=T;c++){
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		int a[n+1][m+1]; //trash: a[row][col]={0}// thực chất chỉ là cell[0][0]=0, còn lại là rác
		
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
				if(i*j==0) a[i][j]=0;
				else scanf("%d",&a[i][j]);

		// for(int i=0;i<=n;i++){
		// 	for(int j=0;j<=m;j++)
		// 		cerr<<a[i][j]<<"  ";
		// 	cerr<<endl; 
		// }
				
		//cumulative
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				 a[i][j]+=a[i-1][j]; //cộng dồn hàng
				 a[i][j]+=a[i][j-1]; //cộng dồn cột
				 a[i][j]-=a[i-1][j-1]; //trừ phần double cộng
			}
		// cerr<<"after cumulative\n";
		// for(int i=0;i<=n;i++){
		// 	for(int j=0;j<=m;j++)
		// 		cerr<<a[i][j]<<"  ";
		// 	cerr<<endl; 
		// }


		int size=1;
		int price;
		if(a[1][1]>k) price=0,size=0;
		else price=a[1][1];
		vector<int> cord(4);
		for(int x=1;x<=n;x++)
			for(int y=1;y<=m;y++)  //(x,y) tọa độ điểm đầu, (i,j) tọa độ điểm cuối 
				for(int i=x;i<=n;i++)
					for(int j=y;j<=m;j++){
						int sumMatrix=a[i][j]-a[x-1][j]-a[i][y-1]+a[x-1][y-1];
						if((i-x+1)*(j-y+1)>size && sumMatrix<=k) {
							size=(i-x+1)*(j-y+1);
							price=sumMatrix;
						}
						if((i-x+1)*(j-y+1)==size &&sumMatrix<price){
							price=sumMatrix;
						}
					}
		printf("Case #%d: %d %d\n",c,size,price);
	}

	return 0;
}