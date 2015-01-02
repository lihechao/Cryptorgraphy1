// Fermart.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DATA_TYPE	unsigned long long
#define MAX_TIME 111111
bool Fermart(int n,int t);
DATA_TYPE GCD(DATA_TYPE a,DATA_TYPE b);				//�������Լ��
DATA_TYPE ComputeR(DATA_TYPE a,DATA_TYPE k,DATA_TYPE n);				//����r=a^k mod n
int DecToBin(DATA_TYPE num,int a[]);		//ʮ����ת���ɶ����ƣ����ض�����λ��
int main()
{
	DATA_TYPE n;
	while(1)
	{
		printf("������Ҫ�жϵ�����\n");
		scanf("%lld",&n);
		if(n<=1||(n>2&&n%2==0)||!Fermart(n,n>MAX_TIME?MAX_TIME:n-2))
			printf("%lld��������\n",n);
		else
			printf("%lld������\n",n);
		printf("\n");
	}
	return 0;
}

bool Fermart(int n,int t)
{
	int i;
	DATA_TYPE Rand_Num,r,gcd;
	srand((unsigned int)time(NULL));
	for(i=0;i<t;i++)
	{	
		//ע��������һ�������ж��Ƿ���������ظ������ظ����������ɣ���n�㹻��ʱ����һ�������Ͽ��Ժ���
/*		DATA_TYPE Choosed[MAX_TIME];	//��¼��ѡ�������
		int j,k;
		bool flag;				//����Ƿ����ظ�
		do
		{
			flag=0;
			do
			{
				Rand_Num=rand()%n;
			}while(Rand_Num<=1||Rand_Num>n-1);
			for(j=0;j<i;j++)
			{
				if(Rand_Num==Choosed[j])		//��ѡ���
				{
					flag=1;					//�ñ��λΪ1
					break;
				}
			}
		}while(flag);
		Choosed[i]=Rand_Num;*/
		do
		{
			Rand_Num=rand()%n;
		}while(Rand_Num<=1||Rand_Num>n-1);
		gcd=GCD(Rand_Num,n);
		if(gcd>1)
			return 0;
		else
		{
			r=ComputeR(Rand_Num,n-1,n);
			if(r!=1)
				return 0;
		}
	}
	return 1;	
}

DATA_TYPE GCD(DATA_TYPE a,DATA_TYPE b)
{
	DATA_TYPE r;
	if(0==b)
		return a;
	do
	{
		r=a%b;
		a=b;
		b=r;
	}while(r!=0);
	return a;
}

int DecToBin(DATA_TYPE num,int a[])		//ʮ����ת���ɶ����ƣ����ض�����λ��
{
	int BitNum;
	for(BitNum=0;num;BitNum++)
	{
		if(0==num%2)
			a[BitNum]=0;
		else
			a[BitNum]=1;
		num/=2;		
	}
	return BitNum;
}

DATA_TYPE ComputeR(DATA_TYPE a,DATA_TYPE k,DATA_TYPE n)
{
	DATA_TYPE tmp;
	DATA_TYPE Power[8*sizeof(DATA_TYPE)]={0};
	int i,BitNum;
	int Bin[8*sizeof(DATA_TYPE)]={0};
	BitNum=DecToBin(k,Bin);			//��kת���ɶ����ƣ�������λ������BitNum
	tmp=a;
	Power[0]=tmp;
	for(i=1;i<BitNum;i++)
	{
		tmp=(tmp*tmp)%n;
		Power[i]=tmp;				//Power[i]��¼����a^(2^i) (mod n)��ֵ
	}
	for(i=0,tmp=0;i<BitNum;i++)
	{
		if(Bin[i]==1)
		{
			if(0==tmp)	tmp=1;
			tmp=(tmp*Power[i])%n;
		}
	}
	return tmp;
}