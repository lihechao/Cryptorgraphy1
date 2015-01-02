// Euclid_Extend_Recursion.cpp : �������̨Ӧ�ó������ڵ㡣
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
		printf("�������������������Կհ��ַ��ָ���\n");
		scanf("%d%d",&a,&b);
		if(0==a&&0==b)
		{
			printf("����������������������룡\n\n");
			continue;
		}
		gcd=Euclid_Extend(abs(a),abs(b));
		printf("%d��%d�����Լ����%d\n",a,b,gcd);
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