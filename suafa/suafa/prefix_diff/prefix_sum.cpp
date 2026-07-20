#include <iostream>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int a[100010];

    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    int s[100010];
    for(int i=1;i<= n;i++){
        s[i]=s[i-1]+a[i];
    }
    while (m--){
        int l,r;
        cin >> l >> r;
        cout << s[r]-s[l-1] << endl;
    }
}