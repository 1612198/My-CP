//Bài này có chút biến đổi ở chỗ nó là hình khuyên (torus)
//nghĩa là đầu cuối là liên tiếp (quấn lại á) nên ta cho thêm
//mẹ nx2n là ổn thôi, thật ra là nx(2n-1) là đủ rồi
#include <bits/stdc++.h>
using namespace std;


int a[200][200]={0};  //a[i<=75][j<=2n-1]
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int TC,n;
	scanf("%d",&TC);
	while(TC--){
		scanf("%d",&n);
    	//cerr<<n<<endl;
		for(int i=0;i<n;i++)
			for(int j=1;j<=n;j++){
				scanf("%d",&a[i][j]);
				a[i+n][j] = a[i][j+n] = a[i+n][j+n] = a[i][j];
			}

    	// for(int i=0;i<2*n;i++){
    	//  for(int j=0;j<=n*2;j++){
   		//    cerr<<a[i][j]<<"  ";
    	//  }
   		//  cerr<<endl;
    	// }


    	//cumulative on rows
		for(int i=0;i<2*n;i++){
			for(int j=1;j<=2*n;j++){
				a[i][j]+=a[i][j-1];
			}
		}

	    // cerr<<"after cumulative\n";
	    // for(int i=0;i<2*n;i++){
	    //  for(int j=0;j<=n*2;j++){
	    //    cerr<<a[i][j]<<"  ";
	    //  }
	    //  cerr<<endl;
	    // }

		int ans=-1e9;
		for(int l=1;l<=n;l++){
		    for(int r=l;r-l+1<=n; r++){//r-l+1: số cột của matrix l,r phải <= n
		        //cerr<<"left = "<<l<<" right = "<<r<<endl;
		      	int sumRect=0;
		      	int SumEndAt[200]={0};
		      	int cnt=0;
		      	for(int i=0;i<2*n;i++){
			        sumRect+=a[i][r]-a[i][l-1]; //dùng kĩ thuật lính canh chèn cột 0 trưóc nên chỗ này ko cần if
			        //cerr<<"sum= "<<sumRect<<endl;
			        // SumEndAt[i]=sumRect;
			        cnt++;
			        /*if(cnt<=n)*/ ans=max(ans,sumRect);
			        if(sumRect<0) {sumRect=0; cnt=0;}
			        if(cnt==n) {sumRect=0/*-=SumEndAt[i-n+1]*/; cnt=0;i=i-n+1;} //làm lại nhiều nè
		        }
	        // cerr<<"max sum= "<<ans<<endl;
		    }
		}
		printf("%d\n",ans);
	}
	return 0;
}