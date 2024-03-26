#include <iostream>
using namespace std;
//最短路径
const int MAX = 1000;
const int N = 100; 
int arc[N][N]; 
int CreatGraph();
int BackPath(int n);
int CreatGraph() {
    int i, j, k;  
    int weight;  
    int vnum, arcnum;  
    cout << "请输入顶点的个数和边的个数：";
    cin >> vnum >> arcnum;  
    for (i = 0; i < vnum; i++)
        for (j = 0; j < vnum; j++)
            arc[i][j] = MAX;  
    for (k = 0; k < arcnum; k++) {
        cout << "请输入边的两个顶点和权值：";
        cin >> i >> j >> weight; 
        arc[i][j] = weight; 
    }
    return vnum;  
}
int BackPath(int n) {
    int i, j, temp;  
    int cost[N], path[N]; 
    for (i = 1; i < n; i++) {
        cost[i] = MAX;  
        path[i] = -1;  
    }
    cost[0] = 0;  
    path[0] = -1;  
    for (j = 1; j < n; j++) {
        for (i = j - 1; i >= 0; i--) {
            if (arc[i][j] + cost[i] < cost[j]) {  
                cost[j] = arc[i][j] + cost[i]; 
                path[j] = i;  
            }
        }
    }
    cout << n - 1;  
    i = n - 1;  
    while (path[i] >= 0) {
        cout << "<-" << path[i];  
        i = path[i]; 
    }
    return cost[n - 1];  
}
//多源点最短路径
const int n = 10;  
void Floyd(int arc[n][n], int dist[n][n]) {
    int i, j, k;  
   
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            dist[i][j] = arc[i][j];
    
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
}
//数塔问题 
int DataTower(int d[n][n]); 
int DataTower(int d[n][n])
{
    int MaxAdd[n][n] = {0}, path[n][n] = {0}; 
    for (int j = 0; j < n; j++) {
        MaxAdd[n - 1][j] = d[n - 1][j];
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            if (MaxAdd[i + 1][j] > MaxAdd[i + 1][j + 1]) {
                MaxAdd[i][j] = d[i][j] + MaxAdd[i + 1][j];
                path[i][j] = j;
            } else {
                MaxAdd[i][j] = d[i][j] + MaxAdd[i + 1][j + 1];
                path[i][j] = j + 1;
            }
        }
    }
    // 输出最优路径
    cout << "路径：";
    int j = 0; 
    cout << d[0][0]; 
    j += path[0][0]; 
    for (int i = 1; i < n; i++) { 
        cout << "-->" << d[i][j];
        j = path[i][j];
    }
    cout << endl;
    return MaxAdd[0][0]; 
}
int main() {
    int choice;
    printf("请选择：\n");
    printf("1. 最短路径\n");
    printf("2. 多源点最短路径\n");
    printf("3. 数塔问题 \n");
    scanf("%d", &choice);
    switch(choice) {
        case 1: {
            // 调用最短路径函数
           int vnum = CreatGraph();
           int shortestPathLength = BackPath(vnum);
           cout << "最短路径长度为：" << shortestPathLength << endl;
           return 0;
        }
        case 2: {
            // 调用选择问题函数
            int arc[n][n]; 
            int dist[n][n]; 
            printf("请输入图的邻接矩阵：\n");
            for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
            scanf("%d", &arc[i][j]);
                  }
              }
             Floyd(arc, dist); 
             printf("最短路径矩阵为：\n");
             for (int i = 0; i < n; i++) {
             for (int j = 0; j < n; j++) {
             printf("%d ", dist[i][j]); 
           }
            printf("\n");
         }
           return 0;
        }
        case 3: {
            int d[n][n];
    cout << "请输入数据塔的元素：" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> d[i][j]; // 读入数据塔的元素
        }
    }
    int result = DataTower(d); // 计算数据塔的最大路径和
    cout << "最大路径和为：" << result << endl; // 输出最大路径和
    return 0;
        }
        default: {
            printf("无效选择\n");
            break;
        }
    }
    return 0;
}
