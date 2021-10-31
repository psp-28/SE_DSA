
/*                        			ASSIGNMENT c26
	c program to implement a queue and show basic operations. */


#include<stdio.h>

#define MAX 30


int insert(int[MAX],int);	//function declaration.
int delete(int[MAX]);
int display(int[MAX]);


int front,rear,q[20];		//rear and front are two basic elements of queue.
int key;
int ch;

int main()
 {
 	int op;
 	front=rear=-1;		//declare rear and front =-1 ,that is queue is located from zeroth location.
 	
 	
 	
 	//Menu driven program.
 	do
 	{
 		printf("\n\n____________________________________________________________________");
 		printf("\n\n\t\t\t**** MENU ****\t\t\t");
 		printf("\n\n1.Enter Job");
 		printf("\n2.delete job");
 		printf("\n3.Display the jobs");
 		printf("\n4.Exit");
 		
 		printf("\n_________________________________________________________________________");
 		
 		printf("\n\nPlease enter your choice::");
 		scanf("%d",&op);
 		
 		switch(op)
 		{
 			case 1:
 				printf("\nEnter the element:");
 				scanf("%d",&key);
 				insert(q,key);		//insert function calling .//inserting "key" element into queue"q"
 				break;
 			
 			case 2:
 				delete(q);		//delete function calling.
 				break;
 			case 3:
 				display(q);		//display function calling.
 				break;		                     
 		
 		}
 		
 	

 		
 	}while(op!=4);
	
 	}
 
 

 
//insert function definition.
 
int insert(int q[20],int key)
 {
 	if(front==-1 && rear ==-1)
 	{
 		front++;
 		rear++;
 		q[front]=q[rear]=key;
 	}
 	else
 	{
 		rear++;
 		q[rear]=key;
 	}
 
 }
 
 
 
 //delete function definition.
 
 int delete(int q[20])
 {
  int temp;
  temp=q[front];
  front++;
  
  return(temp);
  
  
  if(front==rear)
  {
  	front=rear=-1;

  }
  else
  {
  	front++;
  }
  return(temp);
  	
 }
 
 
 //display function definition.
 
 int display(int q[20])
 {
 int i;
 for(i=front;i<=rear;i++)
{
	printf("%d\t",q[i]);
}


 
 }
