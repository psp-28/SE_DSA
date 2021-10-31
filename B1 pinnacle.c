 /*Assignment No .B1

 Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of
Second, third and final year of department can be granted membership on request. Similarly
one may cancel the membership of club. First node is reserved for president of club and last
node is reserved for secretary of club. Write C++ program to maintain club member‘s
information using singly linked list. Store student PRN and Name. Write functions to

 */



#include<stdio.h>

//#include<alloc.h>

void create();
void insert();

void del_pre();
void del_sec();

void reverse();
void deletmem();
void count();
void display();

typedef struct sll
{
	int prn;
	char name[20];
	struct sll *link;
}sll;
sll *start,*end;


int main()
{
 int op;

do
{

	printf("\n\n\n\t\t\t*** MENU ***");
	printf("\n\n\t-------------------------------------------------------------");
	printf("\n\n\t1.Create the club\n\n\t2.Add Member\n\n\t3.Delete Member\n\n\t4.Change President\n\n\t5.Change Secretary");
	printf("\n\n\t6.Display Members of Club\n\n\t7.Total Count \n\n\t8.Reverse Order\n\n\t9.Exit");
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

				deletmem();
				break;
			case 4:

				del_pre();
				break;
			case 5:

				del_sec();
				break;
			case 6:

				display();
				break;
			case 7:

				count();
				break;
			case 8:

				reverse();
				break;

		}
	} while(op!=9);
start=NULL;
end=NULL;
return 0;

}
void create()
{

	sll *freshnode,*temp;
	int ch;

	while(1)
	{

		if(start==NULL)
		{

			printf("\n\n\t\tEnter Data for President   ");
				freshnode=malloc(sizeof(sll*));
				printf("\n\n\n\n\tEnter PRN and Name of President \t");
				scanf("%d%s",&freshnode->prn,freshnode->name);
				freshnode->link=NULL;
				start=freshnode;
				temp=freshnode;


				printf("\n\n\t\tEnter Data for Secretary   ");
				freshnode=(sll*)malloc(sizeof(sll*));
				printf("\n\n\n\n\tEnter PRN and Name of Secretary\t");
				scanf("%d%s",&freshnode->prn,freshnode->name);
				freshnode->link=NULL;
				end=freshnode;
				start->link=end;
		}
		else
		{

			freshnode=(sll*)malloc(sizeof(sll*));
			printf("\n\n\n\n\tEnter PRN and name of student to enter into club \t");
			scanf("%d%s",&freshnode->prn,freshnode->name);
			freshnode->link=NULL;
			temp->link=freshnode;
			temp=freshnode;
			freshnode->link=end;
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
	sll *freshnode;
	freshnode=(sll*)malloc(sizeof(sll*));
		printf("\n\n\t\tEnter PRN and name of student to add into club\t");
		scanf("%d%s",&freshnode->prn,freshnode->name);
		freshnode->link=NULL;
	  freshnode->link=start->link;
	  start->link=freshnode;

	  display();

}

void display()
{

	sll *temp1;

	if(start==NULL)
		printf("\n\n\n\tNo member in club");
	else
	{	printf("\n\n\t-*-*-*-*-*-*-*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*");
		printf("\n\n\n\n\t\t\t\t*** Pinnacle Club ***");
		printf("\n\n\t-*-*-*-*-*-*-*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*--*");
		printf("\n\n\t-----------------------------------------------");
		temp1=start;
		printf("\n\n\n\t*** Pinnacle Club  President  ***");
		printf("\n\n\t\t\t%d\t\t%s",temp1->prn,temp1->name);
		printf("\n\n\t-----------------------------------------------");
		temp1=temp1->link;
		printf("\n\n\n\t\t\t\t*** Pinnacle Club  Members  ***");
		printf("\n\n\t\t PRN \t\t Name of student");
		while(temp1->link!=NULL)
		{
			printf("\n\n\t\t%d\t\t%s",temp1->prn,temp1->name);
			temp1=temp1->link;
		}
		printf("\n\n\t-----------------------------------------------");
		printf("\n\n\n\n\t\t\t\t*** Pinnacle Club  Secretary  ***");
		printf("\n\n\t%d\t\t\t\t%s",end->prn,end->name);
		printf("\n\n\t-----------------------------------------------");
	}
}

void del_pre()
{
	sll *temp;
	printf("\n\n\n\n\tNew President Entry \t");
	printf("\n\n\n\n\tEnter PRN and Name of New President \t");
	scanf("%d%s",&start->prn,start->name);
	printf("\n\n\n\n\t Congratulation for New President selection  \t");

			display();


}
void deletmem()
{
	sll *temp,*prev;
	int pos;
	temp=start;
	if(start->link==end)
		printf("\n\n\tNo Member in club only President and Secretary");
	else
	{
		printf("\n\n\tEnter the PRN  to cancle the membership");
		scanf("%d",&pos);
	   while(temp->prn!=pos)
	   {
			prev=temp;
			temp=temp->link;

	   }

	  prev->link=temp->link;
	   free(temp);

	  display();
	}

}
void del_sec()
{
	    printf("\n\n\n\n\tNew SecretaryEntry \t");
		printf("\n\n\n\n\tEnter PRN and Name of New Secretary \t");
		scanf("%d%s",&end->prn,end->name);
		printf("\n\n\n\n\t Congratulation for New Secretary selection  \t");

				display();

}
void count()
{
	sll *temp1;
	int count=1;
	temp1=start;
	if(start==NULL)
		printf("\n\n\t No member in club");
	else
	{
		while(temp1->link!=NULL)
		{

			count++;

			temp1=temp1->link;
		}

			printf("\n\n\tTotal no of members in club are %d Including President and Secretory",count);


			printf("\n\n\tTotal no of members in club are %d excluding President and Secretory",count-2 );
	}
}
void reverse()
{
	sll *temp,*prev,*next;
	end=start;
	if(start==NULL)
		printf("\n\n\tNo member in club");
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
	//printf("\n\n\t\tReverse List");

	display();
	}
}



