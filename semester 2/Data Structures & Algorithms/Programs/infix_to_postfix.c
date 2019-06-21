#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//#define size 20

struct node
{
	char data;
	struct node* next;
};

void postfix(char*,struct node*);
struct node* create_a_stack();
int check1(char,char,struct node*);
int check2(char,char,struct node*);
void pop(struct node*);
void push(char,struct node*);
void display_stack(struct node*);


int main()
{
	char *infix,choice;
	struct node *head;
	int n,i;
	
	head=create_a_stack();
	
		printf("\n Enter total no. of characters in the infix expn : ");
		scanf("%d",&n);
		infix=(char*)malloc(n+1);
		fflush(stdin);
		printf("\n Enter infix expression : ");
		for(i=0;i<n;i++)
		{
			scanf("%c",&infix[i]);
		
		}
	//fflush(stdin);
	//puts(infix);
	/*putchar(infix[8]);
	printf("\n");
	putchar(infix[9]);
	printf("\n");
	putchar(infix[10]);*/
	//printf("%s",infix);
		printf("\n postfix expn is : ");
		postfix(infix,head);
		display_stack(head);
	
	return 0;
}


void postfix(char* arr,struct node* top)
{
	int i=0,k;
	for(i=0;arr[i]!='\0';i++)
	{
		if(arr[i]=='(')
			push(arr[i],top);
		else if(arr[i]==')')
			{
				do
				{
					if((top->next)->data!='(')
						printf("%c",(top->next)->data);
					pop(top);
				}while((top->next)->data!='(');
				pop(top);
			}
		else 
			{
				if(isalnum(arr[i]))
					printf("%c",arr[i]);
				else 
					{
						if(top->next==NULL)
							push(arr[i],top);
						else
							{	
								switch(arr[i])
								{
									case '*' :
									case '/' : k=check1((top->next)->data,arr[i],top);
											   break;
									case '+' :
									case '-' : k=check2((top->next)->data,arr[i],top);
											   break;
								}
							}
					}
			}
	}
}
		
struct node* create_a_stack()
{
	struct node* ptr;
	ptr=malloc(sizeof(struct node*));
	ptr->next=NULL;
	ptr->data=0;
	return ptr;
}
		
		
int check1(char s_e,char arr_e,struct node* top)
{
	//int k;
	switch(s_e)
	{
		case '+' :
		case '-' :
		case '(' : push(arr_e,top);
				   break;
				   //k=0;
				   //return 1;
		default	 : printf("%c",s_e);
				   pop(top);
				   if((top->next)->data=='*' || (top->next)->data=='/')
				    	{
				    		printf("%c",(top->next)->data);
				    		pop(top);
				    	}
				   push(arr_e,top);
				   //k=1;
				   break;
	}
	/*if(k!=0)
		check1((top->next)->data,arr_e,top);	*/
	//else 
		//return 1;
	return 1;
}
		
		
int check2(char s_e,char arr_e,struct node* top)
{
	//int k;
	switch(s_e)
	{
		case '(' : push(arr_e,top);
				   break;
				   //k=0;
				   //return 1;
		default	 : 
					printf("%c",s_e);
				   	pop(top);
				   	if((top->next)->data!='(')
				   		{
				   			printf("%c",(top->next)->data);
				   			pop(top);
				   		}
				   //}while((top->next)->data!='('||(top->next)!=NULL);
				   push(arr_e,top);
				   //k=1;
				   break;
	}
	/*if(k!=0)
		check2((top->next)->data,arr_e,top);*/	
	//else 
		//return 1;
	return 1;
}


void display_stack(struct node* ptr)
{
	//int i=0;
	//printf("\n Elements of stack are : ");
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	//	i++;
		printf("%c",ptr->data);
	}
}
		
		
void push(char newdata,struct node* ptr)
{
	struct node* new_ptr;
	new_ptr=malloc(sizeof(struct node*));
	new_ptr->data=newdata;
	++(ptr->data);
	
	if(ptr->next==NULL)
	{
		new_ptr->next=NULL;
		ptr->next=new_ptr;
	}
	else if(ptr->next!=NULL)
	{
		new_ptr->next=ptr->next;
		ptr->next=new_ptr;
	}
}


void pop(struct node* ptr)
{
	struct node* temp_ptr;
	//if(ptr->next==NULL)
		//return 0;
	//else
	//{
		--(ptr->data);
		if((ptr->next)->next==NULL)
		{
			temp_ptr=ptr->next;
			ptr->next=NULL;
			free(temp_ptr);
		}
		else
		{
			temp_ptr=ptr->next;
			ptr->next=temp_ptr->next;
			free(temp_ptr);
		}
		//return 1;
	//}
}
		
	
	
