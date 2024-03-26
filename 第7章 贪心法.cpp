#include <iostream>
using namespace std;
// �ҵ����Լ��
int CommFactor(int a, int b) {
while (b != 0) {
int temp = b;
b = a % b;
a = temp;
}
return a;
}
// ������ת��Ϊ����������ʽ
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
// TSP����
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
// Prim�㷨
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
    if (k == -1) break; // ���û���ҵ���һ�����㣬�˳�ѭ��
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
cout << "��ѡ��1.��������  2.TSP����  3.Prim�㷨��: ";
cin >> choice;
if (choice == 1) {
    int numerator, denominator;
    // �������
    cout << "Enter the numerator: ";
    cin >> numerator;
    cout << "Enter the denominator: ";
    cin >> denominator;
    // ���ú���
    EgypFraction(numerator, denominator);
} else if (choice == 2) {
    int n, start;
    cout << "��������е�����: ";
    cin >> n;
    // ��̬�����ά����
    int **arc = new int *[n];
    for (int i = 0; i < n; i++) {
        arc[i] = new int[n];
    }
    cout << "��������м�ľ�������������м���ֱ��·����������0��:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arc[i][j];
        }
    }
    cout << "��������ʼ���б�ţ���0��ʼ��: ";
    cin >> start;
    int length = TSP(arc, n, start);
    cout << "TSP·���ĳ�����: " << length << endl;
    // �ͷŶ�̬������ڴ�
    for (int i = 0; i < n; i++) {
        delete[] arc[i];
    }
    delete[] arc;
} else if (choice == 3) {
    int n, w;
    cout << "�����붥�����: ";
    cin >> n;
    int **arc = new int *[n];
    for (int i = 0; i < n; i++) {
        arc[i] = new int[n];
    }
    cout << "�������ڽӾ���:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arc[i][j];
        }
    }
    cout << "��������ʼ����: ";
    cin >> w;
    Prim(arc, n, w);
    for (int i = 0; i < n; i++) {
        delete[] arc[i];
    }
    delete[] arc;
} else {
    cout << "��Ч��ѡ��" << endl;
}
return 0;
}
