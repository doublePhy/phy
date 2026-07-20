#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[100005];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<a[0];
    }
    else if(n>1){
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1-i;j++){
                if(a[j]>a[j+1]){
                    swap(a[j],a[j+1]);
                }
            }
        }  
        cout<<a[0];
    }
    return 0;
}