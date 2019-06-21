#include<stdio.h>
#include<stdlib.h>

struct node
	{
		int data;
		struct node *next,*prev;
	};
	
struct node* create_a_dll();
void insert_a_node(int,int,struct node*);
int find_a_node(int,struct node*);
void delete_a_node(int,struct node*);
void display_dll(struct node*);
void modify_a_node(int,int,struct node*);
void delete_all(int,struct node*);
void modify_all(int,int,struct node*);

int main()
{
	struct node* start;
	int choice,index,new_data,old_data,flag=0;
	start=create_a_dll();
	
	do
	{
		printf("\n\n 1. Insert a node ");
		printf("\n 2. Find a node ");
		printf("\n 3. Delete a node ");
		printf("\n 4. Display DLL ");
		printf("\n 5. Modify a node ");
		printf("\n 6. Delete all nodes ");
		printf("\n 7. Modify all nodes ");
		printf("\n 8. Exit "); 
		printf("\n\n Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : do
					 {
					 	printf("\n Enter index of the node to be inserted : ");
					 	scanf("%d",&index);
					 	if(index<0 || index>start->data)
					 	{
						 	printf("\n Invalid index!!");
					 		flag=0;
					 	}
					 	else 
					 		flag=1;
					  }while(flag==0);
					 	
					 printf("\n Enter data value of the node : ");
					 scanf("%d",&new_data);
					 insert_a_node(index,new_data,start);
					 //display_dll(start);
					 break;
					 
			case 2 : if(start->next==NULL)
					 	printf("\n List is empty..!!");
					 else
					 	{
							printf("\n Enter node value to be searched : ");
					 	 	scanf("%d",&new_data);
						 	index=find_a_node(new_data,start);
					 		{
					 			if(index==-1)
					 				printf("\n Element %d not found..!!,new_data");
					        	else 
					 				printf("\n Element %d found at index %d ",new_data,index);
					 		}
					 	}
					 break;
					 
			case 3 : printf("\n Enter node value to be deleted : ");
				 	 scanf("%d",&new_data);
				 	 if(start->next==NULL)
				 	 {
				 	  	printf("\n List is empty..!!");
				 	  	printf("\n No nodes to delete ");
				  	 }
				  	 else 
					 {
					 	index=find_a_node(new_data,start);
				 	 	if(index==-1)
							printf("\n Element not found..!!");
				     	else   
				 	 	{	
				 	 	 delete_a_node(new_data,start);
				 	 	 printf("\n Element deleted successfully..!!");
				   	 	}
				   	 }
				 	  break;
					 
					 
			case 4 : display_dll(start); 
					 break;
					 
			case 5 : printf("\n Enter data of the node to be modified : ");
					 scanf("%d",&old_data);
					 if(start->next==NULL)
				 	 {
				 	  	printf("\n List is empty..!!");
				 	  	printf("\n No nodes to modify ");
				  	 }
				  	 else 
					 {
					 	index=find_a_node(old_data,start);
				 	 	if(index==-1)
							printf("\n Element not found..!!");
				     	else   
				 	 	{
					 	 printf("\n Enter new data for the node : ");
					 	 scanf("%d",&new_data);
				 	 	 modify_a_node(old_data,new_data,start);
				 	 	 printf("\n Element modified successfully..!!");
				   	 	}
				      }
				      break;
				      
			case 6 : printf("\n Enter node value to be deleted : ");
				 	 scanf("%d",&new_data);
				 	 if(start->next==NULL)
				 	 {
				 	  	printf("\n List is empty..!!");
				 	  	printf("\n No nodes to delete ");
				  	 }
				  	 else 
					 {
					 	index=find_a_node(new_data,start);
				 	 	if(index==-1)
							printf("\n Element not found..!!");
				     	else   
				 	 	{	
				 	 	 delete_all(new_data,start);
				 	 	 printf("\n Element(s) deleted successfully..!!");
				   	 	}
				   	 }
				 	  break;
				 	  
				      
			case 7 : printf("\n Enter data of the node to be modified : ");
					 scanf("%d",&old_data);
					 if(start->next==NULL)
				 	 {
				 	  	printf("\n List is empty..!!");
				 	  	printf("\n No nodes to modify ");
				  	 }
				  	 else 
					 {
					 	index=find_a_node(old_data,start);
				 	 	if(index==-1)
							printf("\n Element not found..!!");
				     	else   
				 	 	{
					 	 printf("\n Enter new data for the node : ");
					 	 scanf("%d",&new_data);
				 	 	 modify_all(old_data,new_data,start);
				 	 	 printf("\n Element(s) modified successfully..!!");
				   	 	}
				      }
				      break;
				      
			case 8 : exit(0);
			
		}
		
	}while(choice>=1 && choice<=7);
	return 0;
}
	
	
struct node* create_a_dll()
{
	struct node* newptr;
	newptr=malloc(sizeof(struct node*));
	newptr->next=NULL;
	newptr->prev=NULL;
	newptr->data=0;
	return newptr;
}

void insert_a_node(int index,int new_data,struct node* ptr)
{
	int i,size;
	struct node *newptr;
	
	newptr=(struct node*)malloc(sizeof(struct node*));
	newptr->data=new_data;
	i=0;
	size=ptr->data;
	ptr->data=ptr->data+1;
	
	while(i<index)
	{
		ptr=ptr->next;
		i++;
	}
	
	if(size==index)
		{
			ptr->next=newptr;
			newptr->prev=ptr;
			newptr->next=NULL;
		}
	else
		{
			newptr->next=ptr->next;
			newptr->prev=ptr;
			(ptr->next)->prev=newptr;
			ptr->next=newptr;
		}
}
	
	
int find_a_node(int new_data,struct node* ptr)
{
	int i=0;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
		i++;
		if(ptr->data==new_data)
			return i;
	}
	return -1;
}


void delete_a_node(int new_data,struct node* ptr)
{
	struct node *temp_ptr;
	ptr->data=ptr->data-1;
	while(ptr->next!=NULL)
	{
		if((ptr->next)->data==new_data)
		{
			if((ptr->next)->next!=NULL)
			{
				temp_ptr=ptr->next;
				ptr->next=((ptr->next)->next);
				(ptr->next)->prev=ptr;
				free(temp_ptr);
				break;
			}
			else
			{
				temp_ptr=ptr->next;
				ptr->next=NULL;
				free(temp_ptr);
				break;
			}
		}
		else 
			ptr=ptr->next;
	}
}
			
			
void modify_a_node(int old_data,int new_data,struct node *ptr)
{
	
	while(ptr->next!=NULL)
	{	
		ptr=ptr->next;
		if(ptr->data==old_data)
			{
			 ptr->data=new_data;
			 break;
		    }
	}
}



void delete_all(int new_data,struct node* ptr)
{
	int i=0;
	struct node *temp_ptr,*ref;
	ref=ptr;
	
	while(ptr->next!=NULL)
	{
		if((ptr->next)->data==new_data)
		{
			i++;
			if((ptr->next)->next!=NULL)
			{
				temp_ptr=ptr->next;
				ptr->next=((ptr->next)->next);
				(ptr->next)->prev=ptr;
				free(temp_ptr);
			}
			else
			{
				temp_ptr=ptr->next;
				ptr->next=NULL;
				free(temp_ptr);
				break;
			}
		}
		else 
			ptr=ptr->next;
	}
	ref->data=ref->data-i;
}
			

void modify_all(int old_data,int new_data,struct node *ptr)
{
	
	while(ptr->next!=NULL)
	{	
		ptr=ptr->next;
		if(ptr->data==old_data)
			 ptr->data=new_data;
		    
	}
}


	 				
	
	
void display_dll(struct node* ptr)
{
	int i=0;
	if(ptr->next==NULL)
		{
			printf("\n List is empty!!!");
			printf("\n No nodes to display!!\n ");
		}
	else 
		{
			while(ptr->next!=NULL)
			{
				i++;
				ptr=ptr->next;
				printf("\n Data value in node %d = %d ",i,ptr->data);
			}
		}
}
		
		
 	
