// Euclid.cpp : �������̨Ӧ�ó������ڵ㡣
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
		printf("���������������Կհ��ַ��ָ���\n");
		scanf("%d%d",&a,&b);
		if(0==a&&0==b)
		{
			printf("�������ݴ������������룡\n\n");
			continue;
		}
		gcd=Euclid(abs(a),abs(b));
		printf("���������Լ��Ϊ%d��\n\n",gcd);
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