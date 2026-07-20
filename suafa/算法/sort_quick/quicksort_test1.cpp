#include <iostream>
#include <algorithm>  // for swap
#include <cstdlib>    // for system("chcp") and system("pause")
using namespace std;

const int N = 100005;
int q[N];

void quick_sort(int q[], int l, int r) {
    if (l >= r) return;

    int i = l - 1;
    int j = r + 1;
    int x = q[(l + r) >> 1];

    while (i < j) {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main() {
    system("chcp 65001 > nul");  // 终端切 UTF-8，防乱码

    cout << "请输入 n 和 k：" << endl;
    int n, k;
    cin >> n >> k;

    cout << "请输入 " << n << " 个数：" << endl;
    for (int i = 0; i < n; i++)
        cin >> q[i];

    quick_sort(q, 0, n - 1);

    cout << "第 " << k << " 小的数是：" << q[k - 1] << endl;

    
    system("pause");
    return 0;
}
