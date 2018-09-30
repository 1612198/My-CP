#include<iostream>
using namespace std;

int bs_upper_bound(int a[], int n, int x) {
    int l = 0;
    int h = n; // Not n - 1 cause if not element > x -> return end
    while (l < h) {     //not <= because bên dưói chỉ nhích l=mid+1 còn h vẫn = mid, phủ đủ 2 nhánh,
                        //nếu h=mid-1 thì trên phải có đk return như bs_equal
        int mid = (l + h) / 2;
        if (x >= a[mid]) {
            l = mid + 1;
        } else {
            h = mid;
        }
    }  //sau vòng while, l==h, ép về phần tử duy nhất cần tìm thì nó chứ ai
    return l;
}

int bs_lower_bound(int a[], int n, int x) {
    int l = 0;
    int h = n; // Not n - 1
    while (l < h) {
        int mid = (l + h) / 2;
        cerr<<"low = "<<l<<endl;
        cerr<<"high = "<<h<<endl;
        cerr<<"mid = "<<mid<<endl;
        if (x <= a[mid]) {
            h = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
int main(){
    int a[] = {1,2,2,2,2,2,3,3,3,5,5,5};
    int n = sizeof(a)/sizeof(int);
    cout<<bs_lower_bound(a,n,6)<<endl;
    cout<<bs_upper_bound(a,n,6)<<endl;


    return 0;
Ư