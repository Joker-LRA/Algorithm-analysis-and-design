#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
void insert(int a[],int n){
	for(int i=1;i<n;i++){
		int key=a[i];
		int j=i-1;
		while(j>=0&&a[j]>key){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
	for(int k=0;k<n;k++){
		cout << a[k]<<" ";	
	}	
}
void bubble(int a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j] > a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int k=0;k<n;k++){
		cout << a[k] <<" ";
}
}
void xuanzepaixu(int a[],int n){
	for(int i=0;i<n-1;i++){
		int minindex=i;
		for(int j=1+i;j<n;j++){
			if(a[j]<a[minindex]){
				minindex=j;
			}
		}
		swap(a[i],a[minindex]);
	}
	for(int k=0;k<n;k++){
		cout << a[k] <<" ";
}
}
void tongPaiXu(){
	int b[10],k,n;
	memset(b,0,sizeof(b));
	cin>>n;
	for(int i=0;i<n;i++){
		cin >> k;
		b[k]++;	
	}
	for(int j=0;j<=n;j++){
		while(b[j]>0){
			cout<<j<<" ";
			b[j]--;
		}
	}
	}
void advancedMaoPao(int a[],int n){
	bool swapped;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j] > a[j+1]){
				swap(a[j],a[j+1]);
				swapped=true;
			}
		}
		if(!swapped){
			break;
		}
	}
	for(int k=0;k<n;k++){
		cout << a[k] <<" ";
}
	}

int main(){
	int a[10],n,k;
	cout<<"���볤��Ϊ10������"<<endl; 
	for(int i=0;i<10;i++){
		cout<< "�����ǵ�"<<i+1<<"λ"<<endl; 
		cin >> a[i];
	}
	int choice;
	printf("��ѡ��\n");
	cout<< "1.ð������ 2.�Ľ���ð������ 3.Ͱ���� 4.ѡ������ 5.��������.";
	cin >>choice;
	switch(choice){
		case 1:bubble(a,10);break;
		case 2:advancedMaoPao(a,10);break;
		case 3:tongPaiXu();break;
		case 4:xuanzepaixu(a,10);break;
		case 5:insert(a,10);break;
		case 6:break;
}
	return 0;
} 
