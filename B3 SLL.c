
#include<stdio.h>

//#include<alloc.h>

void create();
void insert();
void int_first();
void int_last();
void int_bet();
void del_first();
void del_last();
void del_bet();
void display();
void reverse();
void delet();
void search();

typedef struct sll
{
int data;
struct sll *link;
}sll;
sll *start;


void main()
{
 int op;

do
{

	printf("\n\n\n\t\t\t*** MENU ***");
	printf("\n\n\t-------------------------------------------------------------");
	printf("\n\n\t1.Create\n\n\t2.Insert\n\n\t3.Delete\n\n\t4.Display");
	printf("\n\n\t5.Search\n\n\t6.Reverse\n\n\t7.Exit");
	printf("\n\n\t-------------------------------------------------------------");
	printf("\n\n\tEnter your choice \t");
	scanf("%d",&op);
		switch(op)
		{
			case 1:

				create();

				break;
			case 2:

				insert();

				break;
			case 3:

				delet();

				break;
			case 4:

				display();

				break;
			case 5:

				search();

				break;
			case 6:

				reverse();

				break;
			//case 7:
				//exit(0);
			//default:
			//printf("\n\n\tWrong choice");
		}
	} while(op!=7);
start=NULL;


}
void create()
{

	sll *freshnode,*temp;
	int ch;

	while(1)
	{
		freshnode=(sll*)malloc(sizeof(sll*));
		printf("\n\n\n\n\tEnter data for new node\t");
		scanf("%d",&freshnode->data);
		freshnode->link=NULL;
		if(start==NULL)
		{
			start=freshnode;
			temp=freshnode;
		}
		else
		{
			temp->link=freshnode;
			temp=freshnode;
		}
	   printf("\n\n\t\tU want add more ?\t");

	   scanf("%d",&ch);
		if(ch==0)
		break;
	}
	display();
}
void insert()
{
	int ch;
	do
	{

	printf("\n\n\n\t\t*** INSERTION MENU ***");
	printf("\n\n\t-----------------------------------------");
	printf("\n\n\t1.First\n\n\t2.Middle\n\n\t3.Last\n\n\t4.Exit\n");
	printf("\n\t-----------------------------------------\n");
	printf("\n\n\tEnter your choice\t");
	scanf("%d",&ch);
		switch(ch)
		{
			case 1:

				int_first();

				break;
			case 2:

				int_bet();

				break;
			case 3:

				int_last();

				break;
			case 4:
				break;
			//default:
				//printf("\n\n\t\tWrong choice");
		}
	} while(ch<4);
}
void int_first()
{
	sll *freshnode;
	freshnode=(sll*)malloc(sizeof(sll*));
		printf("\n\n\t\tEnter data for new node\t");
		scanf("%d",&freshnode->data);
		freshnode->link=NULL;
	  freshnode->link=start;
	  start=freshnode;
	  display();

}
void int_bet()
{
	sll *freshnode,*temp;
	int pos,count=0;
	temp=start;
	if(start==NULL)
		printf("\n\n\tList is emply");
	else
	{
		freshnode=(sll*)malloc(sizeof(sll*));
		printf("\n\n\tEnter data for new node\t");
		scanf("%d",&freshnode->data);
		freshnode->link=NULL;

	   printf("\n\n\tEnter the position\t");
	   scanf("%d",&pos);
	   while(count!=pos-1)
	   {
			temp=temp->link;
			count++;
	   }
	   freshnode->link=temp->link;
	   temp->link=freshnode;
	   display();
	 }


}
void int_last()
{
	sll *freshnode,*temp1;
	temp1=start;
	if(start==NULL)
		printf("\n\n\tList is emply");
	else
	{
		freshnode=(sll*)malloc(sizeof(sll*));
		printf("\n\n\tEnter data for new node");
		scanf("%d",&freshnode->data);
		freshnode->link=NULL;
		while(temp1->link!=NULL)
		{
			temp1=temp1->link;
		}
	  temp1->link=freshnode;

	  display();
	}

}
void display()
{

	sll *temp1;

	if(start==NULL)
		printf("\n\n\n\tList is empty");
	else
	{
		printf("\n\n\n\t\t*** List ***");
		printf("\n\n\n\tDATA\t\tAddress");
		printf("\n\n\t-----------------------------------------------");
		temp1=start;
		while(temp1!=NULL)
		{
			printf("\n\n\t%d\t\t%u",temp1->data,temp1->link);
			temp1=temp1->link;
		}
		printf("\n\n\t-----------------------------------------------");
	}
}
void delet()

{
	int ch;
	do
	{

	printf("\n\n\n\n\t\t*** DELETE MENU ***");
	printf("\n\n\t--------------------------------------");
	printf("\n\n\t1.First\n\n\t2.Middle\n\n\t3.Last\n\n\t4.Exit");
	printf("\n\n\t--------------------------------------");
	printf("\n\n\tEnter your choice\t");
	scanf("%d",&ch);
		switch(ch)
		{
			case 1:

				del_first();

				break;
			case 2:

				del_bet();

				break;
			case 3:

				del_last();

				break;
			case 4:
				break;
			//default:
				//printf("Wrong choice");
		}
	} while(ch<4);
}
void del_first()
{
	sll *temp;
		temp=start;
		if(start==NULL)
			printf("\n\n\tList is emply");
		else
		{
			start=start->link;
			free(temp);
			display();
		}

}
void del_bet()
{
	sll *temp1,*temp;
	int pos,count=0;
	temp=start;
	if(start==NULL)
		printf("\n\n\tList is emply");
	else
	{
		printf("\n\n\tEnter the position");
		scanf("%d",&pos);
	   while(count!=pos-1)
	   {
			temp=temp->link;
			count++;
	   }
	   temp1=temp->link;
	   temp->link=temp1->link;
	   free(temp1);

	  display();
	}

}
void del_last()
{
	sll *temp1,*prev;
	temp1=start;
	if(start==NULL)
		printf("\n\n\tList is emply");
	else
	{
		while(temp1->link!=NULL)
		{
			prev=temp1;
			temp1=temp1->link;
		}
		prev->link=NULL;
		free(temp1);
		if(temp1==start)
		{
			start=NULL;
		}
		display();
	}

}
void search()
{
	sll *temp1;
	int data1,count=1,flag;
	temp1=start;
	if(start==NULL)
		printf("\n\n\tList is emply");
	else
	{
		printf("\n\n\tEnter data for search node\t");
		scanf("%d",&data1);

		while(temp1->link!=NULL)
		{
			if(temp1->data==data1)
			{
				flag=1;
				break;
			}
			else
				flag=0;
			count++;

			temp1=temp1->link;
		}
		if(flag==1)
			printf("\n\n\tData is found at location\t%d",count);

			else
				printf("\n\n\tData is not found ");
	}
}
void reverse()
{
	sll *temp,*prev,*next;
	if(start==NULL)
		printf("\n\n\tList is Empty");
	else
	{


	temp=start->link;
	prev=start;
	prev->link=NULL;
	while(temp!=NULL)
	{
		next=temp->link;
		temp->link=prev;
		prev=temp;
		temp=next;
	}
	start=prev;
	printf("\n\n\t\tReverse List");
	display();
	}
}


