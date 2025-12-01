#include <iostream>
using namespace std;

void selectionSortMax(int a[], int n) {
    for(int i=0;i<n-1;i++){
        int mx=i;
        for(int j=i+1;j<n;j++){
            if(a[j]>a[mx]) mx=j;
        }
        int t=a[i];
        a[i]=a[mx];
        a[mx]=t;
    }
}

void print(int a[], int n){
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    selectionSortMax(a,n);
    print(a,n);
    return 0;
}
