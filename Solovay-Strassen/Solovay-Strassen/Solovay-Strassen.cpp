
#include "stdafx.h"

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_TIME 11111
#define DATA_TYPE	long long
bool Solovay_Strassen(DATA_TYPE n,int t);
int Jacobi(DATA_TYPE a,DATA_TYPE n);
DATA_TYPE ComputeR(DATA_TYPE a,DATA_TYPE k,DATA_TYPE n);				//计算r=a^k mod n
int DecToBin(DATA_TYPE num,int a[]);		//十进制转化成二进制，返回二进制位数
int main()
{
	DATA_TYPE n;
	while(1)
	{
		printf("请输入要判断的数：\n");
		scanf("%lld",&n);
		if(n<=1||(n>2&&n%2==0)||!Solovay_Strassen(n,n>MAX_TIME?MAX_TIME:n-2))
			printf("%lld不是素数\n",n);
		else
			printf("%lld是素数\n",n);
		printf("\n");
	}
	return 0;
}
bool Solovay_Strassen(DATA_TYPE n,int t)
{
	int i;
	DATA_TYPE Rand_Num,r,jac;
	srand((unsigned int)time(NULL));
	for(i=0;i<t;i++)
	{	
		//注释起来这一段用来判断是否有随机数重复，如重复则重新生成，在n足够大时，这一段理论上可以忽略
/*		DATA_TYPE Choosed[MAX_TIME];	//记录已选的随机数
		bool flag;				//标记是否有重复
		do
		{
			flag=0;
			do
			{
				Rand_Num=rand()%n;
			}while(Rand_Num<=1||Rand_Num>n-1);
			for(int j=0;j<i;j++)
			{
				if(Rand_Num==Choosed[j])		//已选择过
				{
					flag=1;					//置标记位为1
					break;
				}
			}
		}while(flag);
		Choosed[i]=Rand_Num;*/
		do
		{
			Rand_Num=rand()%n;
		}while(Rand_Num<=1||Rand_Num>n-1);
		r=ComputeR(Rand_Num,(n-1)/2,n);
		if(!(r==1||r==n-1))
			return 0;
		jac=Jacobi(Rand_Num,n);
		if(jac<0)
			jac=n+jac;
		if(r!=jac)
			return 0;
	}
	return 1;
}

int Jacobi(DATA_TYPE a,DATA_TYPE n)
{
	DATA_TYPE temp,e=0,a1,n1;
	int s;
	if(a==0||a==1)
		return 1;
	temp=a;
	while(temp%2==0)
	{
		temp/=2;
		e++;
	}
	a1=temp;
	if(e%2==0)
		s=1;
	else
	{
		if(n%8==1||n%8==7)
			s=1;
		else if(n%8==3||n%8==5)
			s=-1;
	}
	if(n%4==3&&a1%4==3)
		s=-s;
	n1=n%a1;
	if(a1==1)
		return s;
	else
		return s*Jacobi(n1,a1);
}

int DecToBin(DATA_TYPE num,int a[])		//十进制转化成二进制，返回二进制位数
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
	BitNum=DecToBin(k,Bin);			//将n-1转换成二进制，二进制位数赋给BitNum
	tmp=a;
	Power[0]=tmp;
	for(i=1;i<BitNum;i++)
	{
		tmp=(tmp*tmp)%n;
		Power[i]=tmp;
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