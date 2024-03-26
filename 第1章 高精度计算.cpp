#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
//加法 
int jiafa(){
	char a1[100],b1[100];
	int a[100],b[100],c[10000],lena,lenb,lenc,i,x;
	//初始化 
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	gets(a1);
	gets(b1);
	lena=strlen(a1);
	lenb=strlen(b1);
	//字符转化为数组 
	for(i=0;i<=lena-1;i++) a[lena-i]=a1[i]-48;
	for(i=0;i<=lenb-1;i++) b[lenb-i]=b1[i]-48;
	lenc=1;
	x=0;
	while(lenc<=lena||lenc<=lenb){
		c[lenc]=a[lenc]+b[lenc]+x;
		x=c[lenc]/10;
		c[lenc]%=10;
		lenc++;
	}
	c[lenc]=x;
	if(c[lenc]==0)
	lenc--;
	for(i=lenc;i>=1;i--)
		cout<<c[i];
	cout<<endl;
	return 0;
} 
//减法 
int jianfa(){
	char n[256],n1[256],n2[256];
	int a[256],b[256],c[256],lena,lenb,lenc,i;
	//初始化 
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	gets(n1);
	gets(n2);
	if(strlen(n1)<strlen(n2)||(strlen(n1)==strlen(n2)&&strcmp(n1,n2)<0)){
		strcpy(n,n1);
		strcpy(n1,n2);
		strcpy(n2,n);
		cout<<"-";
	}
	lena=strlen(n1);
	lenb=strlen(n2);
	//字符转化为数组 
	for(i=0;i<=lena-1;i++) a[lena-i]=int(n1[i]-'0');
	for(i=0;i<=lenb-1;i++) b[lenb-i]=int(n2[i]-'0');
	i=1;
	while(i<=lena||i<=lenb){
		if(a[i]<b[i]){
			a[i]+=10;
			a[i+1]--;
		}
		c[i]=a[i]-b[i];
		i++;
	}
	lenc=i;
	while((c[lenc]==0)&&(lenc>1)) lenc--;
	for(i=lenc;i>=1;i--)
		cout<<c[i];
	cout<<endl;
	return 0;
}
//乘法 
int chengfa(){
	char a1[100],b1[100];
	int a[100],b[100],c[100],lena,lenb,lenc,i,j,x;
	//初始化 
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	gets(a1);
	gets(b1);
	lena=strlen(a1);
	lenb=strlen(b1);
	//字符转化为数组 
	for(i=0;i<=lena-1;i++) a[lena-i]=a1[i]-48;
	for(i=0;i<=lenb-1;i++) b[lenb-i]=b1[i]-48;
	for(i=1;i<=lena;i++){
		x=0;
		for(j=1;j<=lenb;j++){
			c[i+j-1]=a[i]*b[j]+x+c[i+j-1];
			x=c[i+j-1]/10;
			c[i+j-1]%=10; 
		}
		c[i+lenb]=x;
	}
	lenc=lena+lenb;
	while((c[lenc]==0)&&(lenc>1)) lenc--;
	for(i=lenc;i>=1;i--)
		cout<<c[i];
	cout<<endl;
	return 0;
}
//除法 
int chufa() {
    char a1[100], c1[100];
    int a[100], c[100], lena, lenc, i, b, x = 0;

    // 初始化
    memset(a, 0, sizeof(a));
    memset(c, 0, sizeof(c));
    cin.getline(a1, sizeof(a1));
    cin >> b;
    lena = strlen(a1);
    // 字符转化为数组
    for (i = 0; i < lena; i++) {
        a[i + 1] = a1[i] - '0';
    }
    for (i = 1; i <= lena; i++) {
        c[i] = (x * 10 + a[i]) / b;
        x = (x * 10 + a[i]) % b;
    }
    lenc = 1;
    while (c[lenc] == 0 && lenc < lena) {
        lenc++;
    }
    for (i = lenc; i <= lena; i++) {
        cout << c[i];
    }
    cout << endl;
    return 0;
}

int main(){
	int a;
	char b;
	cout<<"请选择:\n1:加法,2:减法,3:乘法,4:除法"<<endl;
	cin>>b;
	cin.sync();//清除缓冲区 
	switch (b){
		case '1':
			jiafa();
			break;
		case '2':
			jianfa();
			break;
		case '3':
			chengfa();
			break;
		case '4':
			chufa();
			break;
	}
	return 0;
}
