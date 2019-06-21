/*************************************************************************************************************/
/*		Author:   Shubham Gupta 								     */
/*************************************************************************************************************/
#include<stdio.h>
#include<math.h>
long long int gcd(long long int a,long long int b)
{
	if(b%a==0)
		return a;
	else
		gcd(b%a,a);
}
unsigned long long int nCr(int n,int m)
{
	int k;
	int i,j;
	long long int c,d,t;
	c=d=1;
	k=(m>(n-m))?m:(n-m);
	for(j=1,i=k+1;(i<=n);i++,j++)
	{
		c*=i;
		d*=j;
		t=gcd(c,d);
		c/=t;
		d/=t;
	}
return c;
}

int main(void)
{
	int n,m,test;
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&m);
		printf("%llu\n",nCr(n-1,m-1));
	}
	return 0;
}
