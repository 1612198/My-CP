//print all subnet of a set having n number (n<32)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int p[32];
    scanf("%d",&n);
    int cnt =0;
    for(int i=0;i<n;i++)
        scanf("%d",p+i); //scan set

    for(int i=0;i<(1<<n);i++){//having 2^n subnet of a set n elements
        for(int j=0;j<n;j++)  //check all bit of i
            if(i&(1<<j)){   //i&(1<<j): get bit j of number i
                            //chỉ để vậy thôi vì bit-wise return ra khác -> phải sánh với bit còn 
                            //nếu muốn để >0 thì phải ép kiểu về integer: int(N&(1<<i))>0
                printf("%d ",p[j]);
            }
        printf("\n");
        cnt++;
    }
    printf("%d",cnt);
    return 0;
}
