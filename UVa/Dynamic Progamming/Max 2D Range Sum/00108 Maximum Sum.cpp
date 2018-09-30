#include <bits/stdc++.h>
using namespace std;

int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int n;
	while(scanf("%d",&n)!=EOF){
		int a[n][n];
		for(int i=0;i<n;i++)   //read input
			for(int j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				cerr<<a[i][j]<<"  ";
			cerr<<endl;
		}

		for(int i=0;i<n;i++)  //cumulative theo dòng
			for(int j=0;j<n;j++)
				if(j>0) a[i][j]+=a[i][j-1];
		cerr<<"after con don: \n";
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				cerr<<a[i][j]<<"  ";
			cerr<<endl;
		}

		int ans=-127*100*100; //min 
		for(int l=0;l<n;l++){
			for(int r=l;r<n;r++){
				cerr<<"left = "<<l<<" right= "<<r<<endl;
				int sumRect=0; //Rectangle l,r
				for(int i=0;i<n;i++){ //xổ dọc
					if(l>0) sumRect+=a[i][r]-a[i][l-1];
					else sumRect+=a[i][r]; //dồn từ trên xuống nữa
					ans=max(ans,sumRect); //trước cái gán sum=0 vì ans can negative number
					if(sumRect<0) sumRect=0;
				}
				cerr<<"max sum="<<ans<<endl;
			}
		}
		printf("%d\n",ans);

	}

	return 0;
}