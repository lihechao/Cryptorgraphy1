// Euclid_Extend_Recursion.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<stdio.h>
#include<math.h>
int x,y;
int Euclid_Extend(int a,int b);
int main()
{
	int a,b,gcd;
	while(1)
	{
		printf("请输入两个整整数，以空白字符分隔：\n");
		scanf("%d%d",&a,&b);
		if(0==a&&0==b)
		{
			printf("输入的数据有误，请重新输入！\n\n");
			continue;
		}
		gcd=Euclid_Extend(abs(a),abs(b));
		printf("%d和%d的最大公约数是%d\n",a,b,gcd);
		printf("%d=(%d)*(%d)+(%d)*(%d)\n\n",gcd,x*(a<0?-1:1),a,y*(b<0?-1:1),b);
	}
	return 0;
}

int Euclid_Extend(int a,int b)
{
	int m,n;
	if(0==b)
	{
		x=1;
		y=0;
		return a;
	}
	else
	{
		n=Euclid_Extend(b,a%b);
		m=x;
		x=y;
		y=m-a/b*y;
		return n;
	}
}