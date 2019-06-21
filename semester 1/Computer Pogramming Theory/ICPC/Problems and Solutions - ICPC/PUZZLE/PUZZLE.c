/*************************************************************************************************************/
/*		Author:   Shubham Gupta 								     */
/*************************************************************************************************************/
#include<stdio.h>
#include<math.h>
int main()
{
	int i,test;
	long long int t,p,q,s,n;
	//freopen("3.in","r",stdin);
	//freopen("31.out","w",stdout);
	scanf("%d",&test);
	while(test--)
	{
		scanf("%lld",&n);
		s=0;
		p=(int )sqrt(n);
		for(i=1;i<=p;i++)
		{
			t=n/i;
			q=t-i+1;
			s=s+q;	
		}
		printf("%lld\n",s);
	}
	return 0;
}
