//实现C = A * B, A >= 0, B >= 0（高精度 × 高精度）

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> mul(vector<int> &A, vector<int> &B)
{
    // 乘积最多 A.size() + B.size() 位
    vector<int> C(A.size() + B.size(), 0);

    for (size_t i = 0; i < A.size(); i++) {
        int t = 0;  // 进位
        for (size_t j = 0; j < B.size(); j++) {
            t += C[i + j] + A[i] * B[j];  // 累加：原值 + 当前乘积 + 进位
            C[i + j] = t % 10;
            t /= 10;
        }
        C[i + B.size()] = t;  // 内层循环结束后的进位，落在更高位
    }

    // 去掉前导零
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}

int main(){
    string n, m;
    cin >> n >> m;

    vector<int> A, B;
    for (int i = n.size() - 1; i >= 0; i--) A.push_back(n[i] - '0');
    for (int i = m.size() - 1; i >= 0; i--) B.push_back(m[i] - '0');

    vector<int> C = mul(A, B);
    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    system("pause");
}
