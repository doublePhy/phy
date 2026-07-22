//离散化基础模板  一个无序数列的离散映射

#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;

int a[N];   // 原始输入数组，存放所有待离散数字
int id[N];  // 单独数组存每个数字对应的离散编号，不破坏原数据

int main(){
    int n;
    cin>>n;

    // 1、读入数据，存储到 a[1]~a[n]
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    // 2、排序 + 去重，得到有效离散表 a[1]~a[len]
    sort(a+1, a+n+1);
    int len = unique(a+1, a+n+1) - (a+1);

    cout << "去重后的离散表：";
    for(int i=1;i<=len;i++){
        cout << a[i] << " ";
    }
    cout << "\n";

    // 3、给原始每个数字求离散映射编号（1起始）
    cout << "原始数字 -> 离散编号：\n";
    for(int i=1;i<=n;i++){
        // 在去重数组里二分查找，返回指针减数组名a，得到1开头下标1
        id[i] = lower_bound(a+1, a+len+1, a[i]) - a;
        cout << "原数：" << a[i] << " 映射编号：" << id[i] << "\n";
    }

    return 0;
}