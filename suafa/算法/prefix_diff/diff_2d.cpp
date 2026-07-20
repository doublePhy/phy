#include <iostream>
using namespace std;
const int N = 1005;
int a[N][N], D[N][N];

int main(){
    int n,m,q;
    cin >> n >> m >> q;

    // 读入矩阵，初始化二维差分数组D
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            D[i][j] = a[i][j] - a[i-1][j] - a[i][j-1] + a[i-1][j-1];
        }
    }

    // 处理所有矩形加值操作
    while(q--){
        int x1, y1, x2, y2, val;
        cin >> x1 >> y1 >> x2 >> y2 >> val;
        D[x1][y1] += val;
        D[x1][y2+1] -= val; 
        D[x2+1][y1] -= val;
        D[x2+1][y2+1] += val;
    }

    // 差分还原原矩阵，逐行输出
    for(int i=1; i<=n;i++){
        for(int j=1; j<=m; j++){
            a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + D[i][j]; 
            cout << a[i][j] << " ";
        }
        cout << endl; // 每行结束换行
    }

    system("pause");
    return 0; // 补充main返回值
}