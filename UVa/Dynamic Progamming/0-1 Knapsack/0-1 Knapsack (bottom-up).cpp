#include <bits/stdc++.h>
using namespace std;

int i,w,n,S;
int F[1000][1000];
int V[1000],W[1000];

int main()
{
	freopen("0-1 Knapsack_in.txt","r",stdin);
    freopen("0-1 Knapsack_out.txt","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
		scanf("%d",V+i);
	for(int i=0;i<n;i++)
		scanf("%d",W+i);
	cin>>S;
	for(int i=0;i<n;i++)
		cerr<<V[i]<<" ";
	cerr<<endl;
	for(int i=0;i<n;i++)
		cerr<<W[i]<<" ";
	cerr<<endl;
	cerr<<S<<endl;
	//F[i][j]: gía trị lớn nhât mà balo có thể chứa 
	//trong các item từ 0->i-1 và sức chứa balo là j
	//=> đáp án là F[n][S];

	for (i = 0; i <= n;  i++) F[i][0] = 0;  //size balo = 0, ko thể mặc (chọn) gì hết => value=0
      for (w = 0; w <= S; w++) F[0][w] = 0; //i==0, ko có cái gì để mặc(chọn) hết => value=0 ,cần cho về sau

      for (i = 1; i <= n; i++)
        for (w = 1; w <= S; w++) {
          if (W[i] > w) F[i][w] = F[i - 1][w];
          else          F[i][w] = max(F[i - 1][w], V[i] + F[i - 1][w - W[i]]);
        }

    int  ans = F[n][S];
	printf("%d\n",ans);

	for(int i=0;i<n;i++){
		for(int m=0;m<=S;m++){
			cerr<<F[i][m]<<" ";
		}
		cerr<<endl;
	}

	return 0;
}