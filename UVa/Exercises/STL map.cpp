#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string,int> m;
    m["monkey"] = 4;
    m["banana"] = 3;
    m["harpsichord"] = 9;
    for(map<string,int>::iterator it=m.begin();it!=m.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

    return 0;
}
//tự sort theo first (key) s