#include <stdio.h>

using namespace std;
int main()
{
	int n;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &n);
	while(n){
		bool coIn = 0;
		for (int fghij = 1234; fghij <= 98765 / n; fghij++){
			int abcde = fghij*n;
			int tmp, used = (fghij < 10000);
			tmp = abcde;
			while (tmp){
				used |= 1 << (tmp % 10);
				tmp /= 10;
			}
			tmp = fghij;
			while (tmp){
				used |= 1 << (tmp % 10);
				tmp /= 10;
			}
			if (used == (1 << 10) - 1)//1111111111 (pos x =1 tức là có x)
				printf("%0.5d / %0.5d = %d\n", abcde, fghij, n),coIn=1;
		}
		if (!coIn) printf("There are no solutions for %d.\n", n);
		scanf("%d",&n);
		if(n) printf("\n");
	}
	return 0;
}
