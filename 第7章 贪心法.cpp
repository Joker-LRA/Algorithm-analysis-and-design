#include <iostream>
using namespace std;
// 找到最大公约数
int CommFactor(int a, int b) {
while (b != 0) {
int temp = b;
b = a % b;
a = temp;
}
return a;
}
// 将分数转换为埃及分数形式
void EgypFraction(int A, int B) {
int E, R;
cout << A << "/" << B << "=";
do {
E = B / A + 1;
cout << "1/" << E << "+";
A = A * E - B;
B = B * E;
R = CommFactor(B, A);
if (R > 1) {
A = A / R;
B = B / R;
}
} while (A > 1);
cout << "1/" << B << endl;
return;
}
// TSP问题
int TSP(int **arc, int n, int w) {
int edgeCount = 0, TSPLength = 0;
int min, u, v;
int *flag = new int[n];

for (int i = 0; i < n; i++) {
    flag[i] = 0;
}
u = w;
flag[w] = 1;
while (edgeCount < n - 1) {
    min = INT_MAX;
    for (int j = 0; j < n; j++) {
        if (!flag[j] && arc[u][j] != 0 && arc[u][j] < min) {
            v = j;
            min = arc[u][j];
        }
    }
    TSPLength += arc[u][v];
    flag[v] = 1;
    edgeCount++;
    cout << u << " --> " << v << endl;
    u = v;
}
cout << v << " --> " << w << endl;
TSPLength += arc[u][w];
delete[] flag;
return TSPLength;
}
// Prim算法
void Prim(int **arc, int n, int w) {
int i, j, k, min;
int *lowcost = new int[n];
int *adjvex = new int[n];
for (i = 0; i < n; i++) {
    lowcost[i] = arc[w][i];
    adjvex[i] = w;
}
lowcost[w] = 0;
for (i = 1; i < n; i++) {
    min = INT_MAX;
    k = -1;

    for (j = 0; j < n; j++) {
        if (lowcost[j] != 0 && lowcost[j] < min) {
            min = lowcost[j];
            k = j;
        }
    }
    if (k == -1) break; // 如果没有找到下一个顶点，退出循环
    cout << adjvex[k] << " -- " << k << endl;
    lowcost[k] = 0;
    for (j = 0; j < n; j++) {
        if (arc[k][j] != 0 && arc[k][j] < lowcost[j]) {
            lowcost[j] = arc[k][j];
            adjvex[j] = k;
        }
    }
}
delete[] lowcost;
delete[] adjvex;
}
int main() {
int choice;
cout << "请选择：1.埃及分数  2.TSP问题  3.Prim算法）: ";
cin >> choice;
if (choice == 1) {
    int numerator, denominator;
    // 输入分数
    cout << "Enter the numerator: ";
    cin >> numerator;
    cout << "Enter the denominator: ";
    cin >> denominator;
    // 调用函数
    EgypFraction(numerator, denominator);
} else if (choice == 2) {
    int n, start;
    cout << "请输入城市的数量: ";
    cin >> n;
    // 动态分配二维数组
    int **arc = new int *[n];
    for (int i = 0; i < n; i++) {
        arc[i] = new int[n];
    }
    cout << "请输入城市间的距离矩阵（若两城市间无直接路径，请输入0）:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arc[i][j];
        }
    }
    cout << "请输入起始城市编号（从0开始）: ";
    cin >> start;
    int length = TSP(arc, n, start);
    cout << "TSP路径的长度是: " << length << endl;
    // 释放动态分配的内存
    for (int i = 0; i < n; i++) {
        delete[] arc[i];
    }
    delete[] arc;
} else if (choice == 3) {
    int n, w;
    cout << "请输入顶点个数: ";
    cin >> n;
    int **arc = new int *[n];
    for (int i = 0; i < n; i++) {
        arc[i] = new int[n];
    }
    cout << "请输入邻接矩阵:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arc[i][j];
        }
    }
    cout << "请输入起始顶点: ";
    cin >> w;
    Prim(arc, n, w);
    for (int i = 0; i < n; i++) {
        delete[] arc[i];
    }
    delete[] arc;
} else {
    cout << "无效的选择。" << endl;
}
return 0;
}
