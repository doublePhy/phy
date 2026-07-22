#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    double n;
    cin >> n;

    double l = -10000, r = 10000;
    // 精度足够小，保证 6 位小数正确
    while (r - l > 1e-8)
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= n)
            r = mid;
        else
            l = mid;
    }

    printf("%.6f\n", l);
    return 0;
}