#include <bits/stdc++.h>
using namespace std;

int v,n;
int a[1000];
	
#define MAX 1e9

int main()
{
	freopen("CC in.txt","r",stdin);
	scanf("%d %d\n",&v,&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	
	int c[1000];//c[i]: minimum number of coins to present value i
	memset(c,0,sizeof c);
	c[0]=0;
	// int ans=MAX;
	// for(int i=0;i<=v;i++)
	// 	cerr<<c[i]<<" ";
	// cerr<<endl;
	for(int i=1;i<=v;i++){
		c[i]=MAX;  //khoi tao tai moi vi tri MAX để nó lưu qua các gía trị vòng for
		for(int j=0;j<n;j++){
			if((i-a[j]>=0 && c[i-a[j]]!=0) || a[j]-i==0){ //cần c[trước đo] đã đưọc memset=0
				c[i]=min(c[i],1+c[i-a[j]]);
			}
		}
	}
	for(int i=0;i<=v;i++)
		cerr<<c[i]<<" ";
	cerr<<endl;

	printf("%d\n",c[v]);
	return 0;
}