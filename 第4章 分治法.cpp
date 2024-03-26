#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iomanip> 
using namespace std;
//�鲢���� 
void merge(int* a, int low, int mid, int hight)  //�ϲ�����
{
	int* b = new int[hight - low + 1];  //�� new ����һ����������
	int i = low, j = mid + 1, k = 0;    // kΪ b �����С��
	while (i <= mid && j <= hight)  
	{
		if (a[i] <= a[j])
		{
			b[k++] = a[i++];  //����С�������� b ��������
		}
		else
		{
			b[k++] = a[j++];
		}
	}
	while (i <= mid)  // j ���н�������ʣ��� i ���в����� b ������ 
	{
		b[k++] = a[i++];
	}
	while (j <= hight)// i ���н�������ʣ��� j ���в����� b ������ 
	{
		b[k++] = a[j++];
	}
	k = 0;  //��С��Ϊ 0 ��ʼ����
	for (int i = low; i <= hight; i++)  //�� b �����ֵ���ݸ����� a
	{
		a[i] = b[k++];
	}
	delete[]b;     // ������������󣬽���Ŀռ�����ͷţ����٣�
}
void quicksort(int* a, int low, int hight) //�鲢����
{
	if (low < hight)
	{
		int mid = (low + hight) / 2;
		quicksort(a, low, mid);          
		quicksort(a, mid + 1, hight);    
		merge(a, low, mid, hight);       
	}
}
//����Ӷκ� 
int MaxSum(int a[],int left,int right)
{
    int sum=0;
    if(left==right)
    {
        if(a[left]>0)sum=a[left];
        else sum=0;
    }
    else
    {
        int center=(left+right)/2;
        int leftsum=MaxSum(a,left,center);
        int rightsum=MaxSum(a,center+1,right);
        int s1=0;int lefts=0;
        for(int i=center;i>=left;i--)
        {
            lefts+=a[i];
            if(lefts>s1)s1=lefts;
        }
        int s2=0;int rights=0;
        for(int j=center+1;j<=right;j++)
        {
            rights+=a[j];
            if(rights>s2)s2=rights;
        }
        sum=s1+s2;
        if(sum<leftsum)sum=leftsum;
        if(sum<rightsum)sum=rightsum;
    }
    return sum;
}
//���̸������� 
int tile=1;                   //L�͹��Ƶı��(����)  
int board[100][100];  //����  
/***************************************************** 
* �ݹ鷽ʽʵ�����̸����㷨 
* ��������� 
* tr--��ǰ�������Ͻǵ��к� 
* tc--��ǰ�������Ͻǵ��к� 
* dr--��ǰ���ⷽ�����ڵ��к� 
* dc--��ǰ���ⷽ�����ڵ��к� 
* size����ǰ���̵�:2^k 
*****************************************************/  
void chessBoard ( int tr, int tc, int dr, int dc, int size )  
{  
    if ( size==1 )    //���̷����СΪ1,˵���ݹ鵽�����  
        return;  
    int t=tile++;     //ÿ�ε���1  
    int s=size/2;    //�����м���С��к�(��ȵ�)  
    //������ⷽ���Ƿ������Ͻ���������  
    if ( dr<tr+s && dc<tc+s )              //��  
        chessBoard ( tr, tc, dr, dc, s );  
    else         //���ڣ��������������½ǵķ�����Ϊ���ⷽ��  
    {  
        board[tr+s-1][tc+s-1]=t;  
        chessBoard ( tr, tc, tr+s-1, tc+s-1, s );  
    }  
    //������ⷽ���Ƿ������Ͻ���������  
    if ( dr<tr+s && dc>=tc+s )               //��  
        chessBoard ( tr, tc+s, dr, dc, s );  
    else          //���ڣ��������������½ǵķ�����Ϊ���ⷽ��  
    {  
        board[tr+s-1][tc+s]=t;  
        chessBoard ( tr, tc+s, tr+s-1, tc+s, s );  
    }  
    //������ⷽ���Ƿ������½���������  
    if ( dr>=tr+s && dc<tc+s )              //��  
        chessBoard ( tr+s, tc, dr, dc, s );  
    else            //���ڣ��������������Ͻǵķ�����Ϊ���ⷽ��  
    {  
        board[tr+s][tc+s-1]=t;  
        chessBoard ( tr+s, tc, tr+s, tc+s-1, s );  
    }  
    //������ⷽ���Ƿ������½���������  
    if ( dr>=tr+s && dc>=tc+s )                //��  
        chessBoard ( tr+s, tc+s, dr, dc, s );  
    else         //���ڣ��������������Ͻǵķ�����Ϊ���ⷽ��  
    {  
        board[tr+s][tc+s]=t;  
        chessBoard ( tr+s, tc+s, tr+s, tc+s, s );  
    }  
}  
//��������� 
struct point
{
    int x;
    int y;
};
int Partition(point S[],int first,int end)
{
    int i=first,j=end;
    while(i<j)
    {
        while(i<j&&S[i].y<=S[j].y) j--;
        if(i<j)
        {
            point temp;
            temp=S[i];
            S[i]=S[j];
            S[j]=temp;
            i++;
        }
        while(i<j&&S[i].y<=S[j].y) i++;
        if(i<j)
        {
            point temp;
            temp=S[i];
            S[i]=S[j];
            S[j]=temp;
            j--;
        }
    }
    return i;
}
void QuickSort(point S[],int first,int end)
{
    int pivot;
    if(first<end)
    {
        pivot=Partition(S,first,end);
        QuickSort(S,first,pivot-1);
        QuickSort(S,pivot+1,end);
    }
}

double Distance(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double Closest(point S[],int low,int high)
{
    double d1,d2,d3,d;
    int mid,i,j,index;
    point P[1000];                                   //��ż���P1��P2
    if(high-low==1)                              //ֻ�������㣬���������ľ���
        return Distance(S[low],S[high]);
    if(high-low==2)                              //ֻ�������㣬�������Ծ���
    {
        d1=Distance(S[low],S[low+1]);
        d2=Distance(S[low+1],S[high]);
        d3=Distance(S[low],S[high]);
        if((d1<d2)&&(d1<d3))
            return d1;
        else if(d2<d3)
            return d2;
        else
            return d3;
    }
    mid=(low+high)/2;
    d1=Closest(S,low,mid);                         //�ݹ����������1
    d2=Closest(S,mid+1,high);                      //�ݹ����������2
    if(d1<=d2) d=d1;                               //���������3,������������������
    else d=d2;
    index=0;
    for(i=mid;(i>=low)&&(S[mid].x-S[i].x<d);i--)   //�����㼯��P1
        P[index++]=S[i];
    for(i=mid+1;(i<=high)&&(S[i].x-S[mid].x<d);i++);  //�����㼯��P2
	 
	 P[index++]=S[i];
        QuickSort(P,0,index-1);                     //�Լ���P1��P2��y������������
    for(i=0;i<index;i++)                            //���δ�����P1,P2�еĵ�
    {
        for(j=i+1;j<index;j++)
        {
            if(P[i].y-P[i].y>=d)                    //����y�ķ�Χ����P[i]�������
                break;
            else
            {
                d3=Distance(P[i],P[j]);
                if(d3<d)
                    d=d3;
            }
        }
    }
    return d;
}
//������ת����
void Full(int number,int begin,int size,int **d)
{
	int i, j, k;
	
	if (size == 0)
	{
		return;
	}

	if (size == 1)
	{
		d[begin][begin] = number;
		return;
	}
	
	i = begin;j = begin;
	
	for (k = 0; k < size - 1; k++)
	{
		d[i][j] = number;
		number++;
		i++;
	}
	
	for (k = 0; k < size - 1; k++)
	{
		d[i][j] = number;
		number++;
		j++;
	}
	
	for (k = 0; k < size - 1; k++)
	{
		d[i][j] = number;
		number++;
		i--;
	}
	
	for (k = 0; k < size - 1; k++)
	{
		d[i][j] = number;
		number++;
		j--;
	}
	Full(number, begin + 1, size - 2, d);

} 
int main(){
	cout << "��ѡ��" << endl; 
	cout << "1.�鲢����" << endl; 
	cout << "2.����Ӷκ�" << endl; 
	cout << "3.���̸�������" << endl; 
	cout << "4.������ת����" << endl; 
	cout << "5.���������" << endl; 
	int n;
	cin>>n;
	switch(n){
		//�鲢���� 
		case 1: {
			int n, a[100];
			cout << "�����������е�Ԫ�ظ��� n Ϊ��" << endl;
			cin >> n;
			cout << "���������������е�Ԫ�أ�" << endl;
			for (int i = 0; i < n; i++)
			{
				cin >> a[i];
			}
			quicksort(a, 0, n-1);
			cout << "�鲢������" << endl;
			for (int i = 0; i < n; i++)
			{
				cout << a[i] << " ";
			}
			cout << endl;
			break;
		}
		//����ֶκ� 
		case 2: {
			int a[100];
			cout << "���������������е�Ԫ�أ�" << endl;
    		for (int i = 0; i < 6; i++)
			{
				cin >> a[i];
			}
   			int b=MaxSum(a,0,5);
    		cout << "�����" << endl;
   			cout<<b;
			break;
		} 
		//���̸�������
		 case 3:{
		 	
    		cout << "�������̵�size(��С������2��n����): ";
    		int size;
   			 cin >> size;
    		int index_x, index_y;
   			 cout << "�������ⷽ��λ�õ�����: ";
    		cin >> index_x >> index_y;
    		chessBoard(0, 0, index_x, index_y, size);
    
    		for (int i = 0; i < size; i++)
    		{
      	 	 for (int j = 0; j < size; j++)
     	   {
            cout << setw(4) << board[i][j];
       		 }
        	cout << endl;
  			}
			break;
		 }  
		 //������ת����
		 case 4:{
		 		int number = 1, begin = 0, size;
	cout << "�����뷽��Ľ�����";
	cin >> size;
	int** d = new int*[size];
	for (int i = 0; i < size; i++)
	{
		d[i] = new int[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			d[i][j] = 0;
		}
	}
	Full(number, begin, size,d);
	cout << "������ת����" << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout<<d[i][j]<<" ";
		}
		cout << endl;
	}
			break;
		 } 
		 //���������
		 case 5:{
		 	 struct point S[1000];
		 	 cout<<"����Ϊ��"<<endl;
			   
    		int n;
    		cin>>n;
    		cout<<"�ֱ��ǣ�"<<endl;
    		for(int i=0;i<n;i++)
        	cin>>S[i].x>>S[i].y;
   		 	for(int i=0;i<n-1;i++)
   		 	{
        	for(int j=0;j<n-i-1;j++)
            if(S[j].x>S[j+1].x)
            {
                point temp=S[j+1];
                S[j+1]=S[j];
                S[j]=temp;
            }
    		}
    		cout<<Closest(S,0,n-1);
			break;
		 } 
		 default:break; 
	}
	return 0;
}
