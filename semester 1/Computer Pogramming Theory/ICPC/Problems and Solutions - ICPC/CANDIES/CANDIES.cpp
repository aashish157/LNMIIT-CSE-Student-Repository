#include<stdio.h>
#include<math.h>

main()
{
	int p,m,n,i,j,t,count = 0;
	float tmp,tmp1;
	int t1,t2; 
	long long int N ;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lld",&N);
		count = 0;	
		for( p=0;p<N;p++)
		{	if((4*p*p - 8*(p*p-N))>=0 && (2*p > sqrt(4*p*p - 8*(p*p-N))))
			{
			tmp = (2*p + sqrt(4*p*p - 8*(p*p-N)));
			tmp1 = 	(2*p - sqrt(4*p*p - 8*(p*p-N)));
			//printf("%f %f",tmp,tmp1);
			t1 = (int)tmp%4;
			t2 = (int)tmp1%4;	
			//printf("%d %d ", t1,t2);
			if(t1 == 0 && t2 ==0)
			{
				count = 1;
			}	
			}
		}
	if(count==1)
		printf("Yes\n");
	else
		printf("No\n");
	}
}	
