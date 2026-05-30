
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    //输入数据
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    //输入数据为0个
    if(n == 0){
        cout << "0" << endl;
        return 0;
    }



    int maxline=1;//设置一个最大连续长度的变量，初始值为1，因为至少有一个数字是连续的
    int counter=1;
    //开始判断
    for (int i = 0; i < n-1; i++){
    if(a[i+1] - a[i] == 1){
        counter++;
    }
    else {
        counter = 1;
        }
    if(counter > maxline){
        maxline = counter;
    }
    }

    cout << maxline << endl;
    return 0;
}