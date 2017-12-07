#include <bits/stdc++.h>

int main()
{
	int n,b[10005],c[10005];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&c[i]);
	int min1=b[0],min2=c[0];
	for(int i=1;i<n;i++){
		if(b[i]<min1) min1=b[i];
		if(c[i]<min2) min2=c[i];
	}
	printf("%lld",min1+min2);

	return 0;
}