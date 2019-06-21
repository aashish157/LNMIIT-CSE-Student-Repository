#include<stdio.h>
#include<stdlib.h>
#include<math.h>

bool checkforprime(int a);

int maxnum = 0;
int primelist[1000000];

void getlist()
{
	primelist[0] = 2;
	primelist[1] = 3;
	maxnum = 2;
	for( int a = 5; a < 5000000 ; a++)
	{
		if(a%2 !=0 )
		{	
			if(checkforprime(a))
			{
				primelist[maxnum] = a;
				maxnum++;
				//printf("%d\n",a);
			}
		}
	}
	//printf("List generated");
	return;
}
bool checkforprime(int a)
{
	int root = (int)sqrt(a);
	int i;
	for(i = 3 ; i <= root ; i +=2)
	{
		if(a%i == 0)
			return false;
	}
	return true;
}

bool checkfromlist(long long int a)
{
	int checker = 0;

	while(checker < maxnum && a > 1)
	{
		if(a%primelist[checker] == 0)
		{
			printf("%d\n",primelist[checker]);
			a /= primelist[checker];
			checker--;
		}
		checker++;
	}
	if(checker == maxnum)
		printf("%lld\n",a);
	return true;
}


int main(int argc, char** argv) 
{
	getlist();
	//printf("%d \n",maxnum);
	long long int num;
	scanf("%lld",&num);
	int a,b,i,j;

	while(num >= 0)
	{
		if(num == 0 || num == 1)
		{	
			printf("%lld\n",num);
		}
		else
		{
			checkfromlist(num);
		}
		scanf("%lld",&num);
		if(num >= 0)
			printf("\n");
	}
	return 0;
}
