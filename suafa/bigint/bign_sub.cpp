//实现C = A - B, A >= 0, B >= 0

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

// 比较 A 和 B 的大小：A >= B 返回 true，否则 false
bool cmp(vector<int> &A, vector<int> &B)
{
    if (A.size() != B.size())
        return A.size() > B.size(); //这里返回的是 A > B 的结果 布尔值：真或假qu 
    // 位数相同，从高位往低位比
    for (int i = A.size() - 1; i >= 0; i--) {
        if (A[i] != B[i])
            return A[i] > B[i];
    }
    return true;  // 完全相等
}


// C = A - B，调用前保证 A >= B
vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    int t = 0;  // 借位：0 表示没有借位，1 表示向上一位借了 1
    for (size_t i = 0; i < A.size(); i++) {
        t = A[i] - t;                // 先扣掉上一位的借位
        if (i < B.size()) t -= B[i]; // 再减 B 的当前位
        C.push_back((t + 10) % 10);  // t<0 时 +10 还原，t>=0 时不变
        if (t < 0) t = 1;            // 向高位借 1
        else       t = 0;            // 不需要借位
    }
    // 去掉前导零（但至少保留一位，比如 0 本身）
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

    if (cmp(A, B)) {
        vector<int> C = sub(A, B);
        for (int i = C.size() - 1; i >= 0; i--)
            cout << C[i];
    } else {
        vector<int> C = sub(B, A);
        cout << "-";
        for (int i = C.size() - 1; i >= 0; i--)
            cout << C[i];
    }
    system("pause");
}
