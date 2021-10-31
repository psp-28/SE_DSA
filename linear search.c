/* Program of linear search  */


//header files and library.
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 30

//defining the functions for search.
void bubble(int a[],int);
int linear(int a[],int,int);


// initialising the variables.

int key,n,i,j;
int a[MAX];

//main function.
int main()
{
	
	
	int op;
	//do while looping.
	do
	{
		printf("\n\n1.linear search");
		
		
		printf("\n\nEnter ur choice");
		scanf("%d",&op);
		
		//switch case loop.
		
		switch(op)
		{
			
			case 1:
				printf("\n\nEnter the number of elements::");
				scanf("%d",&n);
				
				printf("\n\nEnter the elements::");
				for(i=0;i<n;i++)
				{
					scanf("%d",&a[i]);
				}
				printf("\n\nEnter the number u want to search::");
				scanf("%d",&key);
				
				linear(a,key,n);
				break;
				
						
		
		}
	
	
	}
	while(op!=11);
	
}

//parameterised linear search function.

int linear(int a[],int key,int n)
{
	int flag,i;
	
	for(i=0;i<n;i++)
	{
	
	if(a[i]==key)
	{
		printf("\n\nThe student attended the program");
		flag=1;
		break;
		
	}
	else
	{
		flag=0;
		
	}
	if(flag==0)
	{
		printf("\n\nStudent has not attended the program");
	}
}
}
