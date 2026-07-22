//双指针——最长连续不重复子序列 
#include <iostream>
using namespace std;
const int N = 100000;
int a[N];
int b[N];
int main()
{
    int n;
    cin >>n;
    for(int i = 0; i < n; i++)
    {
        cin >>a[i];
    }

    int res=0;
    int l=0;
    for(int r=0; r < n; r++)
    {
        b[a[r]]++;
        while(b[a[r]]>1){
            b[a[l]]--;// 踢掉左边界的数，一直到能踢到重复的数字停止，这时候r，l相遇，继续找不重复的连续数字的区间
            l++;    
        }
        res = max(res,r-l+1);
    }
    cout << res;
    system("pause");
}