#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int,int>& a,pair<int,int>& b){
    return (a.second<b.second);
}
bool  comp2(string &s1,string& s2){
    return s1[2]<s2[2];
}
int main()
{
    vector<pair<int,int>> vii;
    for(int i=0;i<10;i++)
        vii.push_back(make_pair(i,10-i+1));

    for(int i=0;i<10;i++){
        cout<<vii[i].first<<" "<<vii[i].second<<"\n";
    }

    sort(vii.begin(),vii.end()); //default is sort by first element
    cout<<"vii after sort by default \n";
    for(int i=0;i<10;i++){
        cout<<vii[i].first<<" "<<vii[i].second<<"\n";
    }
    cout<<"vii after sort by third parameters comp\n";
    sort(vii.begin(),vii.end(),comp);
    for(int i=0;i<10;i++){
        cout<<vii[i].first<<" "<<vii[i].second<<"\n";
    }

    vector<string> vstr;
    vstr.push_back("1234");
    vstr.push_back("2315");
    vstr.push_back("3426");
    vstr.push_back("4507");
    sort(vstr.begin(),vstr.end(),comp2);
    for(int i=0;i<vstr.size();i++){
        cout<<vstr[i]<<" ";
    }


    return 0;
}
