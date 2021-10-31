 #define MAX 30
#include<stdio.h>

void insert(int[]);
void display(int[]);
void Union(int[],int[],int[]);
void diff(int[],int[],int[]);

int total; 

void main()
{
	int n,i;
	int ch;
//	int ch1;
  char ab;	
	int setA[MAX],setB[MAX],setC[MAX],setD[MAX],setE[MAX],setF[MAX],setG[MAX];
	setA[0]=setB[0]=setC[0]=setD[0]=setE[0]=setF[0]=setG[0]=0;

do
	{
	   printf("\n\n\t---------------------------------------------------------------");
	   printf("\n\n\t\t\t ***Menu*** \n\n\t\t\t");
	   printf("\n\n 1.Insert elements \n\n 2.student who play cricket \n\n 3.student who play badminton");
	   printf("\n\n 4.student who plays both cricket and badminton(B U C)");
	   printf("\n\n 5.students who play only cricket(B-C)");
	   printf("\n\n 6.students who play only badminton(C-B)");
	   printf("\n\n 7.student who play neither cricket nor badminton");
	   printf("\n\n 8.exit");
	   printf("\n\nEnter the number of your choice displayed in menu");
	   scanf("%d",&ch);
	   
	   switch(ch)
	   		{
	   		  case 1:
	   		             printf(" total number of students");
	   		             insert(setA);
	   		             printf("\n Total students who play cricket");
	   		             insert(setB);
	   		             printf("Total students who play badminton");
	   		             insert(setC);
	   		             break;
	   		             
	   		  case 2: 
	   		             printf("\n .........cricket.........");  
	   		             display(setB);
	   		             
	   		             break;
	   		  case 3:
	   		            printf("\n..........badminton.........");
	   		             display(setC);
	   		             break;
	   		  case 4: 
	   		            Union(setB,setC,setD);
	   		            printf("\n students who play both games are:");
	   		            display(setD);
	   		            break;  
	   		   
	   		  case 5:
	   		            diff(setB,setC,setE);
	   		            printf("\n students who play only cricket(B-C)");
	   		            display(setE);
	   		            break;
	   		     
	   		  case 6:
	   		           diff(setB,setC,setF);
	   		           printf("\n students who plays only badmiton(C-B)");
	   		           display(setF);
	   		  case 7:
	   		           diff(setB,setC,setG);
	   		           printf("\n students who play neither cricket nor badminton");
	   		           display(setG);
	   		           break;
	   		                     
	 		 }                  
//	 printf("\n\n Do you want to contine? (0/1): ");
//	 scanf("%d",&ch1); 
	 
//	 if(ch1==0)
//	 break;

	printf("\nDo u want to continue(y/n): ");
	fflush(stdin);			//fflush(stdin) function is used when while loop execute only once and while(ab=='y') fails so we flush the input and hence loop continues.
	scanf("%c",&ab);
	}
//	while(ch!=8);
	while(ab=='y'||ab=='Y');
}

void insert(int set[])
{
		  int n,i;
		  set[0]=0;
		  printf("\n Total number of students");
		  scanf("%d",&n);
		  set[0]=n;
		  printf("\n Enter the roll no. of the students:");
		   	
	          for(i=1;i<=n;i++)
		{
		  scanf("%d",&set[i]);
		}
}

 void display(int set[])
 {
 	int n,i;
 	n=set[0];
 	if(n==0)
 	
 	{
 	printf("\n NULL ");
 	}
 	
 	else
 	{
 	printf("\n The total students are:%d",n);
 	
 	printf("\n Roll nos.are=\t");
 	
 	printf("{");
 	for(i=1;i<=n;i++)
 	{	
 		          
 	 		printf("\t%d",set[i]);
			
 	 }
 	 printf("}");
 }	 
} 	 
  	
 void Union( int setA[],int setB[],int setC[])
 {
 int n1,m,flag,n,i,j;
 n=setA[0];
		for(i=0;i<=n;i++)
			{
			setC[i]=setA[i];
			}
 			m=n;
 			m++;
 			n1=setB[0];
 			for(i=1;i<=n1;i++)
 			{
 				for(j=1;j<=n;j++)
 			{
 			if(setB[i]!=setA[j])
 				{
 				flag=1;
 				}
 			else
 				{ 
 				flag=0;
 				break;
 			        }
 				
 			}
 	if(flag==1)
 	{
		
		 setC[0]++;
		 setC[m]=setB[i];
		 m++;
		 }

}
  		
  		
  }		
  		

void diff(int setA[],int setB[],int setC[])
{
int i,j,n,n1,m=1,flag=1;
n=setA[0]; 
n1=setB[0];
setC[0]=0;
 	for(i=1;i<=n;i++)
 		{
 			for(j=1;j<=n1;j++) 		
  			{
  			if(setA[i]!=setB[j])
  			
  			 flag=1;
  			 
  			 else 
  			 {
  			 flag=0;
  			 break;
  			 }
  			 }
  	if(flag==1)
  	{
  	setC[m]=setA[i];
  	setC[0]++;
  	m++;
  	}
  	
}	
}
			
