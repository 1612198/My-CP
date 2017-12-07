#include <bits/stdc++.h>

bool isPrime(int x){
	if(x<2) return false;
	else if(x==2) return true;
	else 
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0) return false;
	return true;
}

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	for(int i=a;i<=b;i++)
		if(isPrime(i)) printf("%d\n",i);

	return 0;
}