/*
 * Sai Cheemalapati
 * UVA 507: Jill rides again
 *
 */

#include<cstdio>

using namespace std;

int b, s, n[30000];

int main() {
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d", &b);
    for(int i = 1; i <= b; i++) {
        scanf("%d", &s);
        n[0] = 0;
        for(int j = 1; j < s; j++)
            scanf("%d", &n[j]);
        int a = 0, b = 0, c = 0, sum = 0, max = 0;
        for(int j = 1; j < s; j++) {
            sum += n[j];
            if(sum > max || (sum == max && j - a > b - c)) {
                max = sum;
                b = j;  //cuối -- lấy ts b nghĩa là đến stop b+1
                c = a;  //đầu
            }
            if(sum < 0) {
                a = j;  //đầu tại số âm, mà a[j] chinh là từ j->j+1 nên ta sẽ lấy từ j+1
                sum = 0;
            }
        }
        if(max > 0)
            printf("The nicest part of route %d is between stops %d and %d\n", i, c + 1, b + 1); //như trên đã giải thích
        else
            printf("Route %d has no nice parts\n", i);
    }
}