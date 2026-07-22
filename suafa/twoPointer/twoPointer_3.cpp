//数组元素的目标和         题目前提，数据是升序输入的，即从小到大
#include <iostream>
using namespace std;
const int N=100000;
int a[N],b[N];
int main()
{
    int n,m,x;
    cin>>n>>m>>x;  
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }


    //思路：使用双指针来操作升序数组，双指针的初始位置为0和m-1，i从左边从小往大找，j从右边从大往小找
    //若和小于目标值，则要变大：i++。若和大于目标值，则j要变小：j--。若和等于目标值，则输出下标，或者值,并且i++，j--。
    int i=0,j=m-1;
    while(i<n && j>=0 ){
        if(a[i]+b[j]==x){
            cout << i << " " << j << endl;//输出下标 也可以改为输出值
            i++;
            j--;
            continue;
        }else if(a[i]+b[j]<x){
            i++;
        }else{
            j--;
        }
    }
    system("pause");
}