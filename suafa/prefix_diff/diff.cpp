#include <iostream>

using namespace std;
const int N =100010;

int main(){
    int n, m;
    cin >> n >> m;
    int a[N];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

   int b[N];
   for(int i = 1; i <= n; i++){
    b[i] = a[i] - a[i-1];
   }


   int l,r,c;
   while(m--){
    cin >> l >> r >> c;
    b[l] += c; //没选中的区间，选中区间的临界值因为修改了值，导致与前或者后的没选中的数的差值有变化
    b[r+1] -= c; //选中的区间，b[r+1]及其之后的部分不会被修改，因为区间内集体加1，互相差值不变
   }

   for(int i = 1; i <= n; i++){
    a[i]=a[i-1]+b[i];
   }

   for(int i = 1; i <= n; i++){
    cout << a[i] << " ";
   }
   system("pause");
}