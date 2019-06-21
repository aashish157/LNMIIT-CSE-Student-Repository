#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};


struct node* create_a_stack();
void push(int,struct node*);
int pop(struct node*);
void display_stack(struct node*);

int main()
{
	struct node* top;
	int choice,newdata,x;
	top=create_a_stack();
	
	do
	{
		printf("\n\n 1.PUSH");
		printf("\n 2.POP ");
		printf("\n 3.Display stack");
		printf("\n 4.Exit");
		printf("\n\n Enter your choice : ");
		scanf("%d",&choice);
	
		switch(choice)
		{
			case 1 : printf("\n Enter data to be pushed : ");
			 		 scanf("%d",&newdata);	
			 		 push(newdata,top);
			 		 printf("\n Success..!!");
			 		 break;
			 
			case 2 : x=pop(top);
				 	 if(x==0)
				 	 	printf("\n Underflow..!!");
				 	 else if(x==1)
				 	 	printf("\n Success..!!");
					 break;
			 
			case 3 : if(top->next==NULL)
			 			printf("\n Stack is empty..!!");
			 		 else
			 			display_stack(top);
			 		 break;
			 	
			 case 4 : exit(0);
		}
	}while(choice>=1 && choice<=4);
return 0;
}



struct node* create_a_stack()
{
	struct node* ptr;
	ptr=malloc(sizeof(struct node*));
	ptr->next=NULL;
	ptr->data=0;
	return ptr;
}


void push(int newdata,struct node* ptr)
{
	struct node* new_ptr;
	new_ptr=malloc(sizeof(struct node*));
	new_ptr->data=newdata;
	ptr->data=ptr->data+1;
	
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


int pop(struct node* ptr)
{
	struct node* temp_ptr;
	if(ptr->next==NULL)
		return 0;
	else
	{
		ptr->data=ptr->data-1;
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
		return 1;
	}
}
			
		
		
	


void display_stack(struct node* ptr)
{
	//int i=0;
	printf("\n Elements of stack are : ");
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	//	i++;
		printf("\n %d ",ptr->data);
	}
}
		
		
		
		
