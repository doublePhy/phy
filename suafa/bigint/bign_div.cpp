//实现C = A / B, A >= 0, B > 0（高精度 ÷ 低精度）

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

// A / b = C ... r（r 通过引用返回余数）
vector<int> div(vector<int> &A, int b, int &r)
{
    vector<int> C;
    r = 0;
    // 从高位往低位处理
    for (int i = A.size() - 1; i >= 0; i--) {
        r = r * 10 + A[i];  // 余数 ×10 加上当前位，构成当前被除数
        C.push_back(r / b);  // 商的一位
        r %= b;              // 更新余数
    }
    // C 现在是正序的（高位在前），翻转成低位在前，和加减乘统一
    reverse(C.begin(), C.end());
    // 去掉前导零
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}

int main(){
    string n;
    int b;
    cin >> n >> b;

    vector<int> A;
    for (int i = n.size() - 1; i >= 0; i--) A.push_back(n[i] - '0');

    int r;
    vector<int> C = div(A, b, r);
    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    cout << endl << r;  // 第二行输出余数
    system("pause");
}
