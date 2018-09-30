#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    stringstream ss;
    string str;
    getline(cin,str);
    int a,b,c;
    char d;
    ss.clear();  //sài clear cho chắc, nó xóa bớt eofw
    ss<<str;
    ss>>a>>b>>c>>d;  //analyse input to components
    cout<<a<<b<<c<<d;

    return 0;
}
