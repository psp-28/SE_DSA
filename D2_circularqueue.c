/*						Assignment on circular queue

				write a c program using circular queue for ordering the pizza
	 
*/

#include<stdio.h>				//header file.
#include<string.h>
			

#define MAX 5		

int enqueue(int q[MAX],int token);				//inserting the elements
int dequeue(int q[MAX]);				//Deleting the elements.
int display(int q[MAX]);				//Displaying the values.				

// Global variable declaration.



int front, rear,q[MAX];
int b;

int token=99;
char a[10];



int main()
{
	int op;
	front=rear=-1;

			//Menu of the program.

		
	do
	{
		printf("\n\n--------------------------------------------------------------------------");
		printf("\n\t\t\tDOMINO'S PIZZA \t\t\t");
		printf("\n---------------------------------------------------------------------------");
		printf("\n\n1.Place the order");
		printf("\n2.Dispatch the order");
		printf("\n3.Track the order");
		printf("\n4.Exit");
		printf("\n------------------------------------------------------------------------------");
		
		printf("\n\nEnter the option you want to apply::");
		scanf("%d",&op);
		
		
		
		
		/*switch(expression)
		{
			case 1: statement;
				break; //optional.
			case 2: statement;
				break;
		}*/
		
		
		switch(op)
		{
			case 1:
				
				if(front==0 && rear==MAX-1)
				{
					printf("\n\n sorry can't palce the order");
					
				}
				else if(rear== front-1)
				{
					printf("\n\nsorry can't place the  order");
				}
				else
				{
					printf("\n\npalce the order:");
					scanf("%s",&a[10]);
					
					a[10]=token;
					token++;
					
					printf("\n\nYour token number is %d",token);
					
					printf("\n\n\t\t\t*** THANK YOU ! VISIT AGAIN\t\t\t");
					
					enqueue(q,token);		//Enqueue function calling.
				}
				break;
				
				
			case 2:
				if(front==-1)
				{
					printf("\n\nNO orders are left");
				}	
				else
				{	
					b=dequeue(q);			//dequeue function calling.
					
					printf("\n\nOrder is served for token no - %d",b);
				}
				break;
				
			case 3:
				display(q);				//display function calling.
				break;	
				
				
		
		}
		
	}while(op!=4);	
	
	
}


// Enqueue function declaration.


int enqueue(int q[MAX],int token)

 {
 	if(front==-1 && rear ==-1)
 	{
 		front=0;
 		rear=0;
 		q[front]=q[rear]=token;
 	}
 	else
 	{
 		rear++;
 		q[rear]=token;
 	}
 
 }


// Dequeue function delcaration.


int dequeue(int q[MAX])
{
	int temp;
	
	if(front==rear)
	{
		temp=q[front];
		front=rear=-1;
		return(temp);
	}
	else
	{
		temp=q[front];
		front=(front+1)%MAX;		// front=(front+1)%size   to get position.
		return(temp);
	}

}




// Declaring display function.

int display(int q[MAX])
{
	int i;
		/* if(rear==MAX-1)
		 {
		 	printf("\n Queue is Full");
		 }
 		else*/
 
  	if(front==-1) 
 	{
 		printf("\n Cant place order");
 	}
	 else if(rear>=front)
 	{
 		for(i=front;i<=rear;i++)
 		{
 			printf("\n%d",q[i]);
 		}
 	}
 
 	else 
       	{
		 	for(i=front;i<=MAX-1;i++)
		 	{
		 		printf("\n %d",q[i]);
		 	}	
      			for(i=0;i<=rear;i++)
		 	{
		 		printf("\n %d",q[i]);
		 	}	
      			
      	}
}
	

