#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
//�׳� 
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
//�ۼӺ� 
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
//���ֲ��� 
void search(int x, int top, int bot) {
    int a[11]; 
    int mid; 
    cout << "����10���Ӵ�С˳�����:" << endl;  
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
//������ 
void hanluota(int n, char a, char c, char b) {
    static int k = 0;
    if (n == 0) return; 
    hanluota(n - 1, a, b, c); 
    k++; // ������һ
    cout << k << ": from " << a << " --> " << c << endl;
    hanluota(n - 1, b, c, a);
}
//���ϻ��� 
int partition(int n, int k) {
    if ((n < k) || (k == 0)) 
        return 0;
    if ((k == 1) || (k == n)) 
        return 1;
    return partition(n - 1, k - 1) + k * partition(n - 1, k); 
}
//쳲���������
int fibonacci(int n)
{
    if (n <= 1) 
        return n;
    else 
        return fibonacci(n - 1) + fibonacci(n - 2);
}
int main() {
    int choice;
    printf("��ѡ��\n");
    printf("1. �ۼӺ� \n");
    printf("2. ���ֲ��� \n");
    printf("3. ������ \n");
    printf("4. ���ϻ��� \n");
    printf("5. 쳲���������\n");
    printf("6. �׳�\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1: {
           int t;
            cout << "������һ��������" << endl;
            cin >> t;
            
            if (t > 15) {
                cout << "���볬�����ֵ15�����������룡" << endl;
                break;
        }
        case 2: {
            int x;
            cout << "������һ��������" << endl;
            cin >> x;
            search(x, 1, 10);
            break;
        }
        case 3: {
            int n;
            cout << "�����뺺ŵ���Ĳ�����" << endl;
            cin >> n;
            hanluota(n, 'a', 'c', 'b');
            break;
        }
        case4: {
            int n, k;
            cout << "��������������n��k��" << endl;    //n>k
            cin >> n >> k;
            cout << partition(n, k) << endl;
            break;
        }
        case 5: {
           int n;
            cout << "������Ҫ�����쳲��������е�������";
            cin >> n;
            cout << "�� " << n << " ���ֵΪ��" << fibonacci(n) << endl;
            break;
        }
        case 6:
			jiecheng();
			break;
        default: {
            printf("��Чѡ��\n");
            break;
        }
    }

    return 0;
}
}
