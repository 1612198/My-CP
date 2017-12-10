#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int num[6]={0};
    int bird;
    for(int i=0; i<n; i++){
        cin>>bird;
        num[bird]++;
    }
    int max=num[1],pos=1;
    for(int i=2;i<=5;i++){
        if(num[i]>max){
            max=num[i];
            pos=i;
        }
    }
    cout<<pos;
    return 0;
}
