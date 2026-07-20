#include <iostream>

using namespace std;


int main() {
    int n;
    int x;
    int num;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        while(x){
            x = x & (x - 1);
            num++;
        }
        cout << num << endl;
        num = 0;
        }
    system("pause");
}