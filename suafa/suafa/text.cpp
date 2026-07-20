#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; ++i) {
        cin >> strs[i];
    }
    bool isLex = true;
    bool isLen = true;
    // 检查字典序
    for (int i = 1; i < n; ++i) {
        if (strs[i] < strs[i-1]) {
            isLex = false;
        }
    }
    // 检查长度升序
    for (int i = 1; i < n; ++i) {
        if (strs[i].size() < strs[i-1].size()) {
            isLen = false;
        }
    }
    if (isLex && isLen) {
        cout << "both" << endl;
    } else if (isLex) {
        cout << "islexicalorder" << endl;
    } else if (isLen) {
        cout << "lengths" << endl;
    } else {
        cout << "none" << endl;
    }
    return 0;
}