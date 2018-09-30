/* *Memoization
#include <bits/stdc++.h>
using namespace std;
int v,n;
int a[1000];

int memo[100][1000];

int ways(int type,int value){
	if(value==0) return 1;
	if(value<0 || type==n) return 0;
	int &ret=memo[type][value];
	if(ret!=-1) return ret;
	return ret=ways(type+1,value)+ways(type,value-a[type]);	
}

int main()
{
	freopen("CC in.txt","r",stdin);
	scanf("%d %d\n",&v,&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	memset(memo,-1,sizeof memo);
	int ans=ways(0,v);
	printf("%d\n",ans);

	return 0;
}
*/
//Tabulation
#include <bits/stdc++.h>
using namespace std;

int v,n;;
int a[1000];

int main()
{
	freopen("CC in.txt","r",stdin);
	scanf("%d %d\n",&v,&n);
	cerr<<"v="<<v<<" n="<<n<<endl;
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<=n;i++)
		cerr<<a[i]<<" ";
	cerr<<endl;
	int c[100][1000]; //c[i][j]: so cach chon ra trong set i phan tu, co value =j
	memset(c,0,sizeof c);
	// for(int j=1;j<=v;j++)
		// if(j%a[1]==0) c[1][j]=1;  //base phải có cái gì đó =1 hoặc là trong dp có cộng thêm ngoài.
	for(int i=0;i<=n;i++) c[i][0]=1; //cần thiết, chạy thử sẽ rõ, vd j=5, a[i]=5, lấy 5, c[i][j]= c[i][j-a[i]]=c[i][0]=1 cách chứ đúng ko
	for(int i=1;i<=n;i++){
		for(int j=1;j<=v;j++){
			if(j-a[i]>=0) c[i][j]+=c[i][j-a[i]]; //lay
			c[i][j]+=c[i-1][j];//ko lay
		}
	}

	for(int i=0;i<=n;i++){
		for(int j=0;j<=v;j++)
			cerr<<c[i][j]<<" ";
		cerr<<endl;
	}
	printf("%d\n",c[n][v]);

	return 0;
}