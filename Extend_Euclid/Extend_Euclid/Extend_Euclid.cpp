// Extend_Euclid.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node
{
	int num;
	node *next;
}*Link,Node;
Link top=NULL;	//ջ��
int Extend_Euclid(int a,int b);
int main()
{
	int a,b,gcd,temp;
	int x,y;
	Link p;
	while(1)
	{
		printf("�������������������Կհ��ַ��ָ���\n");
		scanf("%d%d",&a,&b);
		if(0==a&&0==b)
		{
			printf("����������������������룡\n\n");
			continue;
		}
		gcd=Extend_Euclid(abs(a),abs(b));
		printf("%d��%d�����Լ����%d\n",a,b,gcd);
		x=1;
		y=0;
		while(top!=NULL)
		{
			temp=x;
			x=y;
			y=temp-top->num*y;
			p=top;
			top=top->next;				//a/b��ջ
			free(p);
		}
		printf("%d=(%d)*(%d)+(%d)*(%d)\n\n",gcd,x*(a<0?-1:1),a,y*(b<0?-1:1),b);
	}
	return 0;
}

int Extend_Euclid(int a,int b)
{
	int r;
	Link p;
	if(0==b)
		return a;
	do
	{
		p=(Link)malloc(sizeof(Node));
		p->num=a/b;
		p->next=top;
		top=p;				//a/b��ջ
		r=a%b;
		a=b;
		b=r;
	}while(r!=0);
	return a;
}