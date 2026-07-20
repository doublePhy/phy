#include <iostream>
#include <cstdlib>

using namespace std;

void merge_sort(int q[],int l,int r){
    
    if(l>=r) return;


    int mid = (l+r) >> 1;
    merge_sort(q,l,mid);
    merge_sort(q,mid+1,r);

    int i = l;
    int j = mid+1;
    int k = 0;
    int temp[100010];  //写r-l+1也正确 是变量，ISO C++ 禁止变长数组 (VLA)，仅 GCC 编译器拓展能跑，OJ/VS 会编译报错
    while(i<=mid && j<=r){
        if(q[i]<=q[j]) temp[k++]=q[i++];
        else temp[k++]=q[j++];
        res
    }
    
    while(i<=mid) temp[k++]=q[i++];
    while(j<=r)  temp[k++]=q[j++];

    int k=0;
    for(i=l ; i<=r ; i++)
        q[i]=temp[k++];
    
}

int main(){
    int n;
    int q[100010];
    cin>>n;

    for(int i=0;i<n;i++) cin>>q[i];
        merge_sort(q,0,n-1);
    for(int i=0;i<n;i++)
        cout<<q[i]<<" ";

    system("pause");
}