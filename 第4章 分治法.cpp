#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iomanip> 
using namespace std;
//归并排序 
void merge(int* a, int low, int mid, int hight)  //合并函数
{
	int* b = new int[hight - low + 1];  //用 new 申请一个辅助函数
	int i = low, j = mid + 1, k = 0;    // k为 b 数组的小标
	while (i <= mid && j <= hight)  
	{
		if (a[i] <= a[j])
		{
			b[k++] = a[i++];  //按从小到大存放在 b 数组里面
		}
		else
		{
			b[k++] = a[j++];
		}
	}
	while (i <= mid)  // j 序列结束，将剩余的 i 序列补充在 b 数组中 
	{
		b[k++] = a[i++];
	}
	while (j <= hight)// i 序列结束，将剩余的 j 序列补充在 b 数组中 
	{
		b[k++] = a[j++];
	}
	k = 0;  //从小标为 0 开始传送
	for (int i = low; i <= hight; i++)  //将 b 数组的值传递给数组 a
	{
		a[i] = b[k++];
	}
	delete[]b;     // 辅助数组用完后，将其的空间进行释放（销毁）
}
void quicksort(int* a, int low, int hight) //归并排序
{
	if (low < hight)
	{
		int mid = (low + hight) / 2;
		quicksort(a, low, mid);          
		quicksort(a, mid + 1, hight);    
		merge(a, low, mid, hight);       
	}
}
//最大子段和 
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
//棋盘覆盖问题 
int tile=1;                   //L型骨牌的编号(递增)  
int board[100][100];  //棋盘  
/***************************************************** 
* 递归方式实现棋盘覆盖算法 
* 输入参数： 
* tr--当前棋盘左上角的行号 
* tc--当前棋盘左上角的列号 
* dr--当前特殊方格所在的行号 
* dc--当前特殊方格所在的列号 
* size：当前棋盘的:2^k 
*****************************************************/  
void chessBoard ( int tr, int tc, int dr, int dc, int size )  
{  
    if ( size==1 )    //棋盘方格大小为1,说明递归到最里层  
        return;  
    int t=tile++;     //每次递增1  
    int s=size/2;    //棋盘中间的行、列号(相等的)  
    //检查特殊方块是否在左上角子棋盘中  
    if ( dr<tr+s && dc<tc+s )              //在  
        chessBoard ( tr, tc, dr, dc, s );  
    else         //不在，将该子棋盘右下角的方块视为特殊方块  
    {  
        board[tr+s-1][tc+s-1]=t;  
        chessBoard ( tr, tc, tr+s-1, tc+s-1, s );  
    }  
    //检查特殊方块是否在右上角子棋盘中  
    if ( dr<tr+s && dc>=tc+s )               //在  
        chessBoard ( tr, tc+s, dr, dc, s );  
    else          //不在，将该子棋盘左下角的方块视为特殊方块  
    {  
        board[tr+s-1][tc+s]=t;  
        chessBoard ( tr, tc+s, tr+s-1, tc+s, s );  
    }  
    //检查特殊方块是否在左下角子棋盘中  
    if ( dr>=tr+s && dc<tc+s )              //在  
        chessBoard ( tr+s, tc, dr, dc, s );  
    else            //不在，将该子棋盘右上角的方块视为特殊方块  
    {  
        board[tr+s][tc+s-1]=t;  
        chessBoard ( tr+s, tc, tr+s, tc+s-1, s );  
    }  
    //检查特殊方块是否在右下角子棋盘中  
    if ( dr>=tr+s && dc>=tc+s )                //在  
        chessBoard ( tr+s, tc+s, dr, dc, s );  
    else         //不在，将该子棋盘左上角的方块视为特殊方块  
    {  
        board[tr+s][tc+s]=t;  
        chessBoard ( tr+s, tc+s, tr+s, tc+s, s );  
    }  
}  
//最近对问题 
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
    point P[1000];                                   //存放集合P1和P2
    if(high-low==1)                              //只有两个点，返回两点间的距离
        return Distance(S[low],S[high]);
    if(high-low==2)                              //只有三个点，求最近点对距离
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
    d1=Closest(S,low,mid);                         //递归求解子问题1
    d2=Closest(S,mid+1,high);                      //递归求解子问题2
    if(d1<=d2) d=d1;                               //求解子问题3,最近点对在两个集合中
    else d=d2;
    index=0;
    for(i=mid;(i>=low)&&(S[mid].x-S[i].x<d);i--)   //建立点集合P1
        P[index++]=S[i];
    for(i=mid+1;(i<=high)&&(S[i].x-S[mid].x<d);i++);  //建立点集合P2
	 
	 P[index++]=S[i];
        QuickSort(P,0,index-1);                     //对集合P1，P2按y坐标升序排列
    for(i=0;i<index;i++)                            //依次处理集合P1,P2中的点
    {
        for(j=i+1;j<index;j++)
        {
            if(P[i].y-P[i].y>=d)                    //超出y的范围，点P[i]处理完毕
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
//数字旋转方阵
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
	cout << "请选择：" << endl; 
	cout << "1.归并排序" << endl; 
	cout << "2.最大子段和" << endl; 
	cout << "3.棋盘覆盖问题" << endl; 
	cout << "4.数字旋转方阵" << endl; 
	cout << "5.最近对问题" << endl; 
	int n;
	cin>>n;
	switch(n){
		//归并排序 
		case 1: {
			int n, a[100];
			cout << "请输入数列中的元素个数 n 为：" << endl;
			cin >> n;
			cout << "请依次输入数列中的元素：" << endl;
			for (int i = 0; i < n; i++)
			{
				cin >> a[i];
			}
			quicksort(a, 0, n-1);
			cout << "归并排序结果" << endl;
			for (int i = 0; i < n; i++)
			{
				cout << a[i] << " ";
			}
			cout << endl;
			break;
		}
		//最大字段和 
		case 2: {
			int a[100];
			cout << "请依次输入数列中的元素：" << endl;
    		for (int i = 0; i < 6; i++)
			{
				cin >> a[i];
			}
   			int b=MaxSum(a,0,5);
    		cout << "结果是" << endl;
   			cout<<b;
			break;
		} 
		//棋盘覆盖问题
		 case 3:{
		 	
    		cout << "输入棋盘的size(大小必须是2的n次幂): ";
    		int size;
   			 cin >> size;
    		int index_x, index_y;
   			 cout << "输入特殊方格位置的坐标: ";
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
		 //数字旋转方阵
		 case 4:{
		 		int number = 1, begin = 0, size;
	cout << "请输入方阵的阶数：";
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
	cout << "数字旋转方阵：" << endl;
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
		 //最近对问题
		 case 5:{
		 	 struct point S[1000];
		 	 cout<<"点数为："<<endl;
			   
    		int n;
    		cin>>n;
    		cout<<"分别是："<<endl;
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
