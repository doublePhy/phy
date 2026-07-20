#include <iostream>
#include <cstdlib>

typedef long long ll;
using namespace std;

ll merge_sort(int q[],int l,int r){
    if (l>=r) return 0;

    int mid=((l+r) >> 1 );
    ll res=merge_sort(q,l,mid)+merge_sort(q,mid+1,r);
    
    int i=l;
    int j=mid+1;
    int k=0;
    int temp[100010];
    
    while (i <= mid && j<=r){
        if( q[i] > q[j]){
            temp[k++]=q[j++];
            res += mid-i+1;
        }
            else temp[k++]=q[i++];
    }

    while ( i <= mid ) temp[k++]=q[i++];
    while ( j <= r ) temp[k++]=q[j++];

    for(int t=l;t<=r;t++) q[t]=temp[t-l]; 
    
    return res;
}

int main(){
    int n ,q[100010];
    cin>>n;
    for(int i=0;i<n; i++)
        cin>>q[i];

    cout << merge_sort(q,0,n-1) << endl;

    system("pause");
}