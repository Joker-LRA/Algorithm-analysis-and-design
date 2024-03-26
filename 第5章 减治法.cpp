#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//两个序列中位数  
int zhongweishu(int A[], int B[], int n) {
    int s1 = 0, e1 = n - 1, s2 = 0, e2 = n - 1;
    int mid1, mid2;
    while (s1 < e1 && s2 < e2) {
        mid1 = (s1 + e1) / 2;
        mid2 = (s2 + e2) / 2;
        if (A[mid1] == B[mid2]) {
            return A[mid1];
        }
        if (A[mid1] < B[mid2]) {
            if ((s1 + e1) % 2 == 0) {
                s1 = mid1; 
            } else {
                s1 = mid1 + 1;
            }
            e2 = mid2; 
        } else {
            if ((s2 + e2) % 2 == 0) {
                s2 = mid2; 
            } else {
                s2 = mid2 + 1; 
            }
            e1 = mid1; 
        }
    }
    if (A[s1] < B[s2]) {
        return A[s1];
    } else {
        return B[s2];
    }
}
//选择问题 
int Partition(int r[], int low, int high) {
    int i = low, j = high; 
    while (i < j) { 
        while (i < j && r[i] <= r[j]) j--; 
        if (i < j) { 
            int temp = r[i];
            r[i] = r[j];
            r[j] = temp;
            i++;
        }
        while (i < j && r[i] <= r[j]) i++; 
        if (i < j) { 
            int temp = r[i];
            r[i] = r[j];
            r[j] = temp;
            j--;
        }
    }
    return i;
}
int SelectMink(int r[], int low, int high, int k) {
    int s; 
    s = Partition(r, low, high); 
    if (s - low + 1 == k) { 
        return r[s];
    } else if (s - low + 1 > k) { 
        return SelectMink(r, low, s - 1, k); 
    } else { 
        return SelectMink(r, s + 1, high, k - (s - low + 1)); 
    }
}
//折半查找 
int BinSearch1(int r[], int n, int k) {
    
    int low = 0, high = n - 1;  
    int mid; 
    while (low <= high) { 
        mid = (low + high) / 2; 
        if (k < r[mid])
            high = mid - 1;  
        else if (k > r[mid])
            low = mid + 1;   
        else
            return mid;  
    }
    return -1;  
}
//二叉树查找
struct BiNode {
    int data;
    struct BiNode* lchild;
    struct BiNode* rchild;
};
typedef struct BiNode BiNode;
BiNode* SearchBST(BiNode* root, int k) {
     if (root == NULL) {
        return NULL;
    } else if (root->data == k) {
        return root;
    } else if (k < root->data) {
        return SearchBST(root->lchild, k);
    } else {
        return SearchBST(root->rchild, k);
    }
}
BiNode* InsertBST(BiNode* root, int data) {
    if (root == NULL) { 
        root = (BiNode*)malloc(sizeof(BiNode));
        root->data = data;
        root->lchild = root->rchild = NULL;
        return root;
    }
    if (data <= root->data) { 
        root->lchild = InsertBST(root->lchild, data);
    } else { 
        root->rchild = InsertBST(root->rchild, data);
    }
    return root; 
}

BiNode* createBST(int a[], int n) {
    BiNode* T = NULL; 
    for (int i = 0; i < n; i++) { 
        T = InsertBST(T, a[i]);
    }
    return T; 
}
//堆排序 
void SiftHeap(int r[], int k, int n) {
    int i, j, temp;
    i = k; 
    j = 2 * i + 1; 
    while (j < n) { 
        if (j < n - 1 && r[j] < r[j + 1]) 
            j++;
        if (r[i] > r[j]) 
            break;
        else { 
            temp = r[i];
            r[i] = r[j];
            r[j] = temp;
            i = j;
            j = 2 * i + 1;
        }
    }
}
void HeapSort(int r[], int n) {
    int i, temp;
    for (i = (n - 1) / 2; i >= 0; i--)
        SiftHeap(r, i, n); 

    for (i = 1; i <= n - 1; i++) { 
        temp = r[0];
        r[0] = r[n - i];
        r[n - i] = temp;
        SiftHeap(r, 0, n - i);
    }
}
//假币问题 
int Coin(int low, int high, int coins[]) {
    int n = high - low + 1; 
    int num1, num2, num3; 
    int sum1 = 0, sum2 = 0; 
    if (n == 1) { 
        return low;
    }
    if (n % 3 == 0) { 
        num1 = num2 = n / 3;
    } else {
        num1 = num2 = n / 3 + 1;
    }
    num3 = n - num1 - num2; 
    for (int i = 0; i < num1; i++) { 
        sum1 += coins[low + i];
    }
    for (int i = num1; i < num1 + num2; i++) { 
        sum2 += coins[low + i];
    }
    if (sum1 < sum2) { 
        return Coin(low, low + num1 - 1, coins);
    } else if (sum1 > sum2) {
        return Coin(low + num1, low + num1 + num2 - 1, coins);
    } else { 
        return Coin(low + num1 + num2, high, coins);
    }
}
int main() {
    int choice;
    printf("1. 两个序列中位数\n");
    printf("2. 选择问题\n");
    printf("3. 折半查找\n");
    printf("4. 二叉树查找\n");
    printf("5. 堆排序\n");
    printf("6. 假币问题\n");
    printf("请选择：");
    scanf("%d", & choice);
    switch(choice) {
        case 1: {
            // 调用两个序列中位数函数
            int A[100], B[100], n;
            printf("请输入两个序列的元素个数（n）：");
            scanf("%d", &n);
            printf("请输入序列A的元素：");
            for (int i = 0; i < n; i++) {
                scanf("%d", &A[i]);
            }
            printf("请输入序列B的元素：");
            for (int i = 0; i < n; i++) {
                scanf("%d", &B[i]);
            }
            int result = zhongweishu(A, B, n);
            printf("中位数为：%d\n", result);
            break;
        }
        case 2: {
            // 调用选择问题函数
            int arr[100], k, n;
            printf("请输入数组的元素个数（n）：");
            scanf("%d", &n);
            printf("请输入数组的元素：");
            for (int i = 0; i < n; i++) {
                scanf("%d", &arr[i]);
            }
            printf("请输入k的值：");
            scanf("%d", &k);
            int result = SelectMink(arr, 0, n-1, k);
            printf("第 %d 小的元素是：%d\n", k, result);
            break;
        }
        case 3: {
            // 调用折半查找函数
            int r[100], n, k;
            printf("请输入有序数组的元素个数（n）：");
            scanf("%d", &n);
            printf("请输入有序数组的元素：");
            for (int i = 0; i < n; i++) {
                scanf("%d", &r[i]);
            }
            printf("请输入要查找的元素：");
            scanf("%d", &k);
            int result = BinSearch1(r, n, k);
            printf("查找结果：%d\n", result);
            break;
        }
        case 4: {
            // 调用二叉树查找函数
            int a[100], n;
            printf("请输入二叉搜索树的节点个数（n）：");
            scanf("%d", &n);
            printf("请输入二叉搜索树的节点值：");
            for (int i = 0; i < n; i++) {
                scanf("%d", &a[i]);
            }
            BiNode* root = createBST(a, n);
            int searchKey;
            printf("请输入要查找的节点值：");
            scanf("%d", &searchKey);
            BiNode* result = SearchBST(root, searchKey);
            if (result != NULL) {
                printf("找到了，节点值为：%d\n", result->data);
            } else {
                printf("没找到\n");
            }
            break;
        }
        case 5: {
            // 调用堆排序函数
            int r[100], n;
            printf("请输入数组的元素个数（n）：");
            scanf("%d", &n);
            printf("请输入数组的元素：");
            for (int i = 0; i < n; i++) {
                scanf("%d", &r[i]);
            }
            HeapSort(r, n);
            printf("排序后数组: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", r[i]);
            }
            printf("\n");
            break;
        }
        case 6: {
            // 调用假币问题函数
            int coins[100], n;
            printf("请输入硬币的个数（n）：");
            scanf("%d", &n);
            printf("请输入硬币的重量：");
            for (int i = 0; i < n; i++) {
                scanf("%d", &coins[i]);
            }
            int fakeCoinIndex = Coin(0, n-1, coins);
            printf("第%d个硬币为假币。\n", fakeCoinIndex + 1);
            break;
        }
        default: {
            printf("无效选择\n");
            break;
        }
    }
    return 0;
}
