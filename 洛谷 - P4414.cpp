//主要是理解题目意思，题目给了三个数和一个顺序，要求按照这个顺序输出这三个数。首先需要对这三个数进行排序，然后根据输入的顺序来输出对应的数。使用ASCII码之差来判断输出哪个数是一个巧妙的方式，因为输入的顺序是由字符'A'、'B'、'C'组成的，可以通过减去'A'来得到对应的索引。

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    
    // 按数值排序：a[0] < a[1] < a[2]
    sort(a, a + 3);
    
    string order;
    cin >> order;//可能是ABC、ACB、BAC、BCA、CAB、CBA中的一种
    //输入的时候字母之间没空格，所以差值固定，所以使用ASCII码之差来判断输出哪个数
    
    // 按给定顺序输出
    for (int i = 0; i < 3; i++) {
        cout << a[order[i] - 'A'];//使用的是ASCII码之差来判断输出哪个数
        if (i != 2) cout << ' ';  // 最后一个后面不加空格
    }
    
    return 0;
}