//BFS广度优先算法 解决 迷宫问题
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 迷宫最大长宽105，题目数据范围限制
const int N=105;
// 方向数组，控制四个移动方向：右、下、左、上
// dx对应行的变化，dy对应列的变化
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
// dist数组：存储起点走到每个格子的最少步数
// 初始值-1代表该格子未被访问过
int dist[N][N];

int main()
{
    // n代表列数，m代表行数
    int n, m;
    // 输入迷宫行列尺寸
    cin >> n >> m;
    // 创建二维vector存储迷宫地图，m行n列
    // map[i][j] = 0 通路；map[i][j] = 1 墙壁
    vector<vector<int>> map(m, vector<int>(n));

    // 循环读取迷宫每一格数据
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            // 所有格子初始标记为-1，代表未走过
            dist[i][j] = -1;
        }
    }

    // 创建队列，存储坐标pair，存放等待拓展四周的格子
    queue<pair<int, int>> q;    
    // 起点坐标(0,0)放入队列，准备处理
    q.push({0,0});
    // 起点不用移动，步数初始化为0
    dist[0][0] = 0;

    // BFS主循环：队列不为空就持续搜索
    while(!q.empty())
    {
        // 取出队列最前端的格子坐标（当前处理点）
        auto t = q.front();
        // 拆分出行坐标x、列坐标y
        int x=t.first,y=t.second;
        // 将队首元素弹出队列，避免重复处理
        q.pop();

        // 遍历上下左右四个移动方向
        for(int i=0;i<4;i++)
        {
            // 计算当前方向相邻格子的坐标
            int newx=x+dx[i];
            int newy=y+dy[i];

            // 多条件判断：格子合法才能走
            // newx>=0 && newx<m：行坐标不超出迷宫上下边界
            // newy>=0 && newy<n：列坐标不超出迷宫左右边界
            // map[newx][newy]==0：该格子不是墙，可以通行
            // dist[newx][newy]==-1：该格子之前没有访问过
            if(newx>=0 && newx<m && newy>=0 && newy<n && map[newx][newy]==0 && dist[newx][newy]==-1){
                // 将合法新格子加入队列，后续拓展它的四周
                q.push({newx,newy});
                // 新格子步数 = 当前格子步数 + 多走的这一步
                // 同时赋值后dist不再是-1，标记已访问
                dist[newx][newy]=dist[x][y]+1;
            }
            else{
                // 条件不满足，跳过这个方向
                continue;
            }
        }
    }
    // 循环结束后，右下角(m-1,n-1)就是终点，输出最短步数
    cout<< dist[m-1][n-1]<<endl;
    return 0;
}