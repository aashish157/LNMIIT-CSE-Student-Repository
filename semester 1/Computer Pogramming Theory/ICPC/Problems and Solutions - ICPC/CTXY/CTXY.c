#include<stdio.h>

int get_number(char *input);
main()
{
	int i=-1;
	char input[100];
	char input2[100];
	int a[4];
	int num1=0,fact=1, num2=0, num=0;
	int cases;
	scanf("%d",&cases);

	while(cases--)
	{
		scanf("%s",input);
		scanf("%s",input2);
		num1 = get_number(input);
		num2 = get_number(input2);
		num=num1+num2;
		// printf("%d\n",num);
		i=-1;
		fact=1;
		while(num!=0)
		{
			a[++i]=num%10;
			num/=10;
		}
		if(i==3)
		{
			if(a[i]==0)
				printf("");
			else
			{
				if(a[i] == 1) printf("c");
				else
					printf("%dc",a[i]);
			}
			i--;
		}
		if(i==2)
		{
			if(a[i]==0)
				printf("");
			else
			{
				if(a[i]==1) printf("t");
				else
					printf("%dt",a[i]);
			}
			i--;
		}
		if(i==1)
		{
			if(a[i]==0)
				printf("");
			else
			{
				if(a[i]==1) printf("x");
				else
					printf("%dx",a[i]);
			}
			i--;
		}
		if(i==0)
		{
			if(a[i]==0)
				printf("");
			else
			{
				if(a[i]==1) printf("y");
				else
					printf("%dy",a[i]);
			}
		}
		printf("\n");
	}

}



int get_number(char *input)
{
    int i;
    int num=0;
    int fact=1;
    for(i=0;input[i]!='\0';i++)
    {
	if(input[i] == 'c')
	{
	    num+=fact*1000;
	    fact=1;
	}
	else
	if(input[i] == 'x')
	{
	    num+=10*fact;
	    fact=1;
	}
	else
	if(input[i] == 't')
	{
	    num+=100*fact;
	    fact=1;
	}
	else
	if(input[i] == 'y')
	{
	    num+=fact;
	    fact=1;
	}
	else
	{
	    fact=input[i]-'0';
	}
    }
    return num;
}
