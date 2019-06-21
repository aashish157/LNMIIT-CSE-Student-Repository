/*************************************************************************************************************/
/*		Author:   Shubham Gupta 								     */
/*************************************************************************************************************/
#include<stdio.h>
int gcd3(int a,int b,int c)
{
	int s;
	if(a==0 && b==0 && c==0)
		return 0;
	else
	{
		s=gcd(gcd(a,b),c);
		return s;
	}
}
int gcd(int a,int b)
{
	if(a==0)
		return b;
	else
	{
		if(b%a==0)
			return a;
		else
			return gcd(b%a,a);
	}
}
int main()
{
	int n,test,i,j,k,count,t;
	//freopen("2.in","r",stdin);
	//freopen("2.out","w",stdout);
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		count=0;
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=n;j++)
			{
				for(k=0;k<=n;k++)
				{	
					t=gcd3(i,j,k);
					if(t==1)
						count++;
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
