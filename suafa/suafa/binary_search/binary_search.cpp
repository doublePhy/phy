#include <iostream>
#include <cstdlib>
using namespace std;


int n;
int arr[100010];


int binary_search(int x,int type){
    int l=0,r=n-1;
    if(type == 0){// type == 0的时候找左边界的二分
        while(l<r){  
            int mid = (r+l) >>1;
            if(arr[mid] >= x)   r = mid;
            else l = mid + 1;   
        }
    }else{   // type == 1的时候找右边界的二分
        while(l<r){ 
            int mid = (r+l+1) >>1;
            if(arr[mid] <= x)  l=mid;
            else r = mid -1 ;
        }
    }
    
    return l;
}


int main(){
    int q;
    cin >>n >> q;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    while(q--){

        int x;
        cin >> x;
        

        int L=binary_search(x,0);
        int R=binary_search(x,1);

        if(arr[L]!=x) 
        cout<<"-1 -1"<<endl;
        else 
        cout<<L<<" "<<R<<endl;
    }
    
    system("pause");
}