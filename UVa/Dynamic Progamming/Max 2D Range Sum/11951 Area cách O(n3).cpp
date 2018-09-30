#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int c=1;c<=T;c++){
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		int a[n][m];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&a[i][j]);
		// for(int i=0;i<n;i++){
		// 	for(int j=0;j<m;j++)
		// 		cerr<<a[i][j]<<"  ";
		// 	cerr<<endl;
		// }
		//cumulative
		for(int i=0;i<n;i++)
			for(int j=1;j<m;j++)
				 a[i][j]+=a[i][j-1];
		// cerr<<"after cong don hang\n";
		// for(int i=0;i<n;i++){
		// 	for(int j=0;j<m;j++)
		// 		cerr<<a[i][j]<<"  ";
		// 	cerr<<endl;
		// }

		int maxSize,price;
		if(a[0][0]>k) maxSize=0,price=0;
		else maxSize=1,price=a[0][0];
		for(int l=0;l<m;l++){
			for(int r=l;r<m;r++){
				int size=0,pri=0,cnt=0; //number of rows of matrix (r-l+1)x(i+1)
				for(int i=0;i<n;i++){
					size += (r-l+1);
					// cerr<<"size = "<<size<<endl;
					cnt++;
					if(l>0) pri+=a[i][r]-a[i][l-1];
					else pri+=a[i][r];
					if(pri>k){
						pri=0;
						// i-= (size/(r-l+1));
						i-=(cnt-1);
						cnt=0;
						// cerr<<"i="<<i<<endl;
						size=0;
					}
					if(size>maxSize || (size==maxSize&&pri<price)) {maxSize=size;price=pri;}
					
				}
			}
		}
		printf("Case #%d: %d %d\n",c,maxSize,price);

	}

	return 0;
}