#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
//阶乘 
int jiecheng(){
	int a[10000],b[10000];
	int i,j,n;
	cin>>n;
	a[0]=1;
	a[1]=1;
	for(j=1;j<=n;j++){
		memset(b,0,sizeof(b));
		b[0]=a[0];
		for(i=1;i<=a[0];i++){
			b[i]=b[i]+a[i]*j;
			b[i+1]=b[i]/10;
			b[i]=b[i]%10;
		}
		while(b[b[0]+1]>0){
			b[b[0]+2]=b[b[0]+1]/10;
			b[b[0]+1]=b[b[0]+1]%10;
			b[0]++;
		}
		for(i=1;i<=b[0];i++){
			a[i]=b[i];
		}
		a[0]=b[0];
	}
	for(i=a[0];i>=1;i--)
		cout<<a[i];
	cout<<endl;
}
//累加和 
int fac(int n) {
    if (n == 1) return 1; 
    return (fac(n - 1) + n); 
}
long long fac2(int n) {
    if (n == 1) {
        return 1; 
    }
    return fac2(n - 1) * n; 
}
//二分查找 
void search(int x, int top, int bot) {
    int a[11]; 
    int mid; 
    cout << "输入10个从大到小顺序的数:" << endl;  
    for (int k = 1; k <= 10; k++)
        cin >> a[k];
    if (top <= bot) { 
        mid = (top + bot) / 2; 
        if (x == a[mid]) 
            cout << "YES" << endl; 
        else if (x < a[mid]) 
            search(x, mid + 1, bot);
        else
            search(x, top, mid - 1); 
    } else
        cout << "NO" << endl;
}
//汉罗塔 
void hanluota(int n, char a, char c, char b) {
    static int k = 0;
    if (n == 0) return; 
    hanluota(n - 1, a, b, c); 
    k++; // 步数加一
    cout << k << ": from " << a << " --> " << c << endl;
    hanluota(n - 1, b, c, a);
}
//集合划分 
int partition(int n, int k) {
    if ((n < k) || (k == 0)) 
        return 0;
    if ((k == 1) || (k == n)) 
        return 1;
    return partition(n - 1, k - 1) + k * partition(n - 1, k); 
}
//斐波那契数列
int fibonacci(int n)
{
    if (n <= 1) 
        return n;
    else 
        return fibonacci(n - 1) + fibonacci(n - 2);
}
int main() {
    int choice;
    printf("请选择：\n");
    printf("1. 累加和 \n");
    printf("2. 二分查找 \n");
    printf("3. 汉罗塔 \n");
    printf("4. 集合划分 \n");
    printf("5. 斐波那契数列\n");
    printf("6. 阶乘\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1: {
           int t;
            cout << "请输入一个整数：" << endl;
            cin >> t;
            
            if (t > 15) {
                cout << "输入超过最大值15，请重新输入！" << endl;
                break;
        }
        case 2: {
            int x;
            cout << "请输入一个整数：" << endl;
            cin >> x;
            search(x, 1, 10);
            break;
        }
        case 3: {
            int n;
            cout << "请输入汉诺塔的层数：" << endl;
            cin >> n;
            hanluota(n, 'a', 'c', 'b');
            break;
        }
        case4: {
            int n, k;
            cout << "请输入两个整数n和k：" << endl;    //n>k
            cin >> n >> k;
            cout << partition(n, k) << endl;
            break;
        }
        case 5: {
           int n;
            cout << "请输入要计算的斐波那契数列的项数：";
            cin >> n;
            cout << "第 " << n << " 项的值为：" << fibonacci(n) << endl;
            break;
        }
        case 6:
			jiecheng();
			break;
        default: {
            printf("无效选择\n");
            break;
        }
    }

    return 0;
}
}
