#include <bits/stdc++.h>
using namespace std;

int TC,xsize,ysize,n,x[11],y[11],dist[11][11],memo[11][1<<11];

int main()
{
	freopen("10496 in.txt","r",stdin);
	// freopen("10496 out.txt","w",stdout);
	scanf("%d",&TC);
	while(TC--){
		scanf("%d%d",&xsize,&ysize);
		scanf("%d%d",&x[0],&y[0]);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d",&x[i],&y[i]);

		//build distance table
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				dist[i][j]=abs(x[i]-x[j])+abs(y[i]-y[j]);

		int dp[11][1<<11]; //dp[i][j]: path ngắn nhất lúc đang đứng ở city i (kết thúc tại i) và đã đi qua (số bit 1 trong bitmask j) cities.
		dp[0][0]=0;
		// memset(dp,0,sizeof dp);
		for(int bitmask=0;bitmask<(1<<(n+1));bitmask++){
			cerr<<"bitmask="<<bitmask<<endl;
			for(int pos=1;pos<=n;pos++){
				if((bitmask>>(pos))&1){  //bitmask co pos
					int ans=2e9;
					// cerr<<"zo\n";
					for(int nxt=0;nxt<=n;nxt++){
						if(nxt!=pos && (bitmask&(1<<(nxt))))
							ans=min(ans,dist[pos][nxt]+dp[nxt][bitmask^(1<<(pos))]);//xor(^) xóa bit nên < ban đầu và luôn tồn tại >0 do luôn có bit nxt=1
					}
					dp[pos][bitmask]=ans;
				}
				
			}
		}
		for(int i=0;i<11;i++){
			for(int j=0;j<32;j++)
				if(dp[i][j]==2e9) cerr<<"IF ";
				else cerr<< dp[i][j]<<" ";
			cerr<<endl;
		}
		int ans=1e9;
		cerr<<"n="<<n<<endl;
		for(int i=1;i<=n;i++){
			cerr<<dist[i][0]+dp[i][(1<<(n+1))-1]<<"\n";
			ans=min(ans,dp[i][(1<<n)-1]+dist[i][0]);
		}
		printf("The shortest path has length %d\n",ans);

	}

	return 0;
}


/*
	Cái mình cần là 1 thứ tự (hoán vị) sao cho tổng khoảng cách gĩưa 2 cái liên tiếp ngắn nhất
	Tức là ta chọn n city
	Giờ bài toán nhỏ để giải bài này là: Chọn ra subset trong n để có tổng đường đi ngắn nhất
	Ví dụ city dừng chân là pos thì ta coi xem những city trước pos có thứ tự như thế nào là tối ưu
	--> nó có tính hồi quy.
	Nếu đã quyết định đến city này thì ta xem tổng lớn nhất để hoàn thành subnet bỏ city được chọn là bao nhiêu. Vậy thôi.
	Cụ thể:
	Ưng với mỗi bitmask, ta cho điểm cuối lần lượt là 1 trong n city, và tính chi phí tương ứng, sau đó mở rộng bitmask lên
	Ví dụ bitmask có 1 bit 1: điểm cuối là 2 thì chi phí min
	thì bitmask có 2 bit 1: điểm cuối là 3 thì dp[3][bitmask]=min{dist[pos][prev] + dp[prev][bitmask bỏ bit 3]}  //nxt thay pos để làm dấu và previous
*/