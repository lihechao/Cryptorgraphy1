// Euclid.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<stdio.h>
#include<math.h>
int Euclid(int a,int b);
int main()
{
	int a,b,gcd;
	while(1)
	{
		printf("请输入两个数，以空白字符分隔：\n");
		scanf("%d%d",&a,&b);
		if(0==a&&0==b)
		{
			printf("输入数据错误！请重新输入！\n\n");
			continue;
		}
		gcd=Euclid(abs(a),abs(b));
		printf("两数的最大公约数为%d。\n\n",gcd);
	}
	return 0;
}

int Euclid(int a,int b)
{
	int r;
	if(b==0)
		return a;
	do
	{
		r=a%b;
		a=b;
		b=r;
	}while(r!=0);
	return a;
}