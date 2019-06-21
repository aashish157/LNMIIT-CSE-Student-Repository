#include<stdio.h>
#include<stdlib.h>


struct node
{
		int data;
		struct node *next;
};

int size;


struct node* create_new_list();
void insert_node(int,int,struct node*);
void insert_at_end(int,struct node*);
int search_node(int,struct node*);
void delete_node(int,struct node*);
//void delete_all(int,struct node*);
void delete_first_node(struct node*);
void modify_node(int,int,struct node*);
//void modify_all(int,int,struct node*);
void display(struct node*);


int main()
{
	int choice,index=0,new_data,k=0,old_data,flag=0;
	struct node *head,*ptr;
	
	head=create_new_list();
	size=head->data;
	
	do
	{
		printf("\n\n 1. Insert node");
		printf("\n 2. Insert node at the end");
		printf("\n 3. Search node");
		printf("\n 4. Delete node");
		printf("\n 5. Delete first node");
		printf("\n 6. Modify node");
		printf("\n 7. Diplay Linked List ");
		printf("\n 8. Exit");
	
		printf("\n\n Enter choice (1,2,3,4,5,6,7,8) : ");
		scanf("%d",&choice); 
	
		switch(choice)
		{
			case 1 : do
					 {
					 	printf("\n Enter index : ");
					 	scanf("%d",&index);
					 	//printf("%d\n",size);
					 	if(index<0 || index>head->data)
					 		{
							 printf("\n Invalid index!!");
							 flag=0;
							}
						else flag=1;
					 }while(flag==0);
					 printf("\n Enter data value : ");
					 scanf("%d",&new_data);
					 insert_node(index,new_data,head);
					 //display(head);
					 break;
			
			case 2 : printf("\n Enter data of the node to be inserted at the end : ");
					 scanf("%d",&new_data);
					 insert_at_end(new_data,head);
					 break;
					 
			
			case 3 : printf("\n Enter data value to be searched :");
					 scanf("%d",&new_data);
					 k=search_node(new_data,head);
					 if(k==-1)
					 		printf("\n Element %d not found!!!",new_data);
					 else 
					 		printf("\n Element found at index %d\n ",k);
					 break; 				 
			
			case 4 : printf("\n Enter data of node to be deleted : ");
					 scanf("%d",&new_data);
					 k=search_node(new_data,head);
					 if(k==-1)
					 		printf("\n Element %d not found!!!",new_data);
					 else 
					 		{
							 delete_node(new_data,head);
							 printf("\n Deletion was successful ");
							}
					 		//delete_all(new_data,head);
					 //display(head);
					 break;
					 
			case 5 : if(head->next==NULL)
					 	printf("\n List is empty..!!\n");
					 else		
					 	{
						 	delete_first_node(head);
						 	printf("\n Deletion was successful ");
						 }
					 break;
			
			case 6 : printf("\n Enter index of the node to be modified : ");
					 scanf("%d",&index);
					 if(index<1 && index>=size)
					 	printf("\n Invalid index!!!");
					 	//printf("\n Enter data value to be modified : ");
					 	//scanf("%d",&old_data);
					 else
					 	{
					 		printf("\n Enter new data to be entered :");
					 		scanf("%d",&new_data);
					 		//if(index<=0 || index>size)
					 		//printf("\n Invalid index !!! "); 
					 		modify_node(index,new_data,head);
					 		//modify_all(old_data,new_data,head);
					 	}
					 		break;
			
			case 7 : display(head);
					 break;
					 
			case 8 : exit(0);
			
			default: printf("\n Enter a valid choice !! : ");
    		}
    	
    }while(choice>=1 && choice<=7);
    
    return 0;
}
					 
	
struct node* create_new_list()
{
	size=0;
	struct node *ptr;
	ptr=malloc(sizeof(struct node*));
	ptr->data=0;
	ptr->next=NULL;
	return ptr;
}

void insert_node(int index,int new_data,struct node* ptr)
{
    int i;
	struct node *newptr;
	if(index<0 || index > (ptr->data))
	{
		printf("Invalid index..!!!\n\n");
		return;
	}

	newptr = (struct node*)malloc(sizeof(struct node *));
	newptr->data = new_data;

	ptr->data = ptr->data+1;
	i=0;
	while(i < index)
	{
		ptr = ptr->next;
		i++;
	}
	
	newptr->next = ptr->next;
	ptr->next = newptr;
	
}

void insert_at_end(int new_data,struct node* ptr)
{
	struct node *new_ptr;
	
	new_ptr=malloc(sizeof(struct node*));
	new_ptr->next=NULL;
	new_ptr->data=new_data;
	
	ptr->data=ptr->data+1;
	
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=new_ptr;
}

void display(struct node* ptr)
{
	int i=0;
	if((ptr->next)==NULL)
		printf("\n List is empty..!!\n No nodes to display ");
	else
		while((ptr->next)!=NULL)
		{
			ptr=ptr->next;
			i++;
			printf("\n Data of node %d is %d",i,ptr->data);
		}

}

int search_node(int new_data,struct node* ptr)
{
	int index=0,k=-1;
	if(ptr->next==NULL)
		printf("\n List is empty ");
	else 
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
			index++;
			if(ptr->data==new_data)
				{
				 k++;
				 return index;
				 }
			
		}
		return k;	
}


void delete_node(int new_data,struct node* ptr)
{
	struct node *temp_ptr,*ref;
	ref=ptr;
	if(ptr->next==NULL)
		printf("\n List is empty ");
	else 
		{
	 		while(ptr->next!=NULL)
			{
				//ptr=ptr->next;
				if((ptr->next)->data==new_data)
					{
			 			//temp_ptr=((ptr->next)->next);
			 			//ptr->next=temp_ptr;
			 			temp_ptr = ptr->next;
						ptr->next = (ptr->next)->next;
						ref->data=ref->data-1;
						//free(temp_ptr);
			 			break;
					}
				ptr=ptr->next;
			}
		}
	//ref->data=ref->data-1;
	free(temp_ptr);
	
}

void delete_first_node(struct node *ptr)
{
	struct node *temp_ptr,*ref;
	ref=ptr;
	temp_ptr=ptr->next;
	ptr->next=(ptr->next)->next;
	free(temp_ptr);	
	
	ref->data=ref->data-1;	
}
	
	
void modify_node(int index,int new_data,struct node *ptr)
{
	int i=0;
	//struct node *temp_ptr,*ref;
	//ref=ptr;
	while(i<index)
	{
		ptr=ptr->next;
		i++;
	}
	
	ptr->data=new_data;
	
}
