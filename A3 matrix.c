/*
 *                   Assignment No A9
 *
 * Write C/C++ program for storing matrix. Write functions for
 * a) Check whether given matrix is upper triangular or not
 * b) Compute summation of diagonal elements
 * c) Compute transpose of matrix
 * d) Add, subtract and multiply two matrices
 *
 */



#include<stdio.h>

void create(int [4][4],int,int);
void display(int [4][4],int,int);
void add(int[4][4],int [4][4],int [4][4]);
void transpose(int [4][4]);
void mul(int [4][4],int [4][4],int [4][4]);
void  saddle(int [4][4]);
void diangonl(int [4][4]);
void uppertriangular(int [4][4]);

int r=0,c=0,r1=0,c1=0;
int main()
{
	int a[4][4],b[4][4],cc[4][4];
	int ch;
	//char ch1;

	do
	{

		printf("\n\n\n\t\t\t*** MENU ***\n\n") ;
		printf("\n\t\t-----------------------------------------------------");
		printf("\n\n\n\t\t1.Create First Matrix\n\n\t\t2.Create 2nd Matrix\n\n\t\t3.Display 1st Matrix");
		printf("\n\n\t\t4.Display 2nd Matrix\n\n\t\t5.Add two matrices");
		printf("\n\n\t\t6.Multiply two matrices ");
		printf("\n\n\t\t7.Transpose of the 1st Matrix\n\n\t\t8.Saddle point");
		printf("\n\n\t\t9.Sum of Diagonal Elements\n\n\t\t10.Condition of Uppertriangular\n\n\t\t11.Exit\n");
		printf("\n\t\t-----------------------------------------------------");

		printf("\n\n\t\tEnter Your Choice :  ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:

				printf("\n\n\t\tFirst Enter matrix A");
				printf("\n\n\t\t Enter the size of the matrix :");
				scanf("%d%d",&r,&c);
				create(a,r,c);
				break;
			case 2:

				printf("\n\n\t\t Enter matrix B");
				printf("\n\n\t\t Enter the size of the matrix :");
				scanf("%d%d",&r1,&c1);
				create(b,r1,c1);
				break;
			case 3:

				printf("\n\n\n\n\t\t*** Matrix A ***\n\n\n");
				display(a,r,c);

				break;
			case 4:

				printf("\n\n\n\n\t\t*** Matrix B ***\n\n");
				display(b,r1,c1);

				break;

			case 5:

				if(r==r1 && c==c1)
				{
					add(a,b,cc);
					printf("\n\n\n\n\t\t*** Matrix A ***\n\n\n");
					display(a,r,c);
					printf("\n\n\n\n\t\t*** Matrix B ***\n\n\n");
					display(b,r1,c1);
					printf("\n\n\n\n\t\t*** Addition Of Matrix ***\n\n\n");
					display(cc,r,c);
				}
				else
				printf("\n\n\t\t Can't add ");

				break;

			case 6:

				if(r==r1 && c==c1)
				{
					mul(a,b,cc);
					printf("\n\n\n\n\t\t*** Matrix A ***\n\n\n");
					display(a,r,c);
					printf("\n\n\n\n\t\t*** Matrix B ***\n\n\n");
					display(b,r1,c1);
					printf("\n\n\n\n\t\t*** Multiplication Of Matrix ***\n\n\n");
					display(cc,r,c);
				}
				else
				printf("\n\n\t\t Can't multiply ");

				break;

			case 7:
				if(c==r)
				{
					printf("\n\n\n\n\t\t*** Matrix A ***\n\n\n");
					display(a,r,c);
					transpose(a);
					printf("\n\n\t\tTranspose of Matrix A ***\n\n\n");
					display(a,r,c);
					transpose(a);
				}
				/*else
				printf("\Not a square matrix :");*/

				break;


			case 8:

				printf("\n\n\n\n\t\t*** Matrix A ***\n\n\n");
				display(a,r,c);
				saddle(a);
				break;

			case 9:

				printf("\n\n\n\n\t\t*** Matrix A ***\n\n\n");
				display(a,r,c);
				diagonal(a);
				break;

			case 10:

				printf("\n\n\n\n\t\t*** Matrix A ***\n\n\n");
				display(a,r,c);
				uppertriangular(a);
				break;

	}
		/*printf("\n\n\n\n\t\tDo u want to continue\t");

		scanf("%c",&ch1);
		if(ch1=='n')
			break;*/

	  }while(ch!=11);
	return 0;
  }


void create(int a[4][4],int r,int c)
{
	int i,j;
	printf("\n\n\t\t Enter the elements of matrix:");
	for(i=0;i<r;i++)
	{
	   for(j=0;j<c;j++)
			 scanf("%d",&a[i][j]);
	 }
}

void display(int s[4][4],int r,int c)
{
	 int i,j;
	 for(i=0;i<r;i++)
	 {
		printf("\n\n");
		for(j=0;j<c;j++)

		   printf("\t\t%d",s[i][j]);
	 }
}
void add(int a[4][4],int b[4][4],int cc[4][4])
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			cc[i][j]=a[i][j]+b[i][j];
	}
}

void transpose(int a[4][4])
{
	int i,j,temp;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
		  	if(i<j)
		   {
			temp=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=temp;
		  }
		}
	 }
}

void diangonl(int a[4][4])
{
	int i,j,temp=0,n;
	n=r-1;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
		  	if(i==j)
		   {
			temp=temp+a[i][j];
		   	}
		}
	 }
	printf("\n\n\t\t Additional of Left  Diagonal elements =  %d",temp);
	temp=0;
	for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{

			/*	if(i+j==n )
			   {
			  		if(i==n/2 && j==n/2)
			  			temp=temp+a[i][j];
			  		else if(i!=j)
			  			temp=temp+a[i][j];
			   	}*/
				if(i+j==n)
		  		 {
					temp=temp+a[i][j];
		   		}
			}
		 }


	printf("\n\n\t\t Additional of Right Diagonal elements =  %d",temp);
}
void uppertriangular(int a[4][4])
{
	int i,j,temp;

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
		  	if(i>j)
		   {
		  		if(a[i][j]==0)
		  			temp=1;
		  		else{

		  			temp=0;
		  			break;
		  			}

		   	}
		}
	}
		if(temp==1)
			printf("\n\n\n\t\t\tGiven Matrix is Upper triangular");
		else
			printf("\n\n\n\t\t\tGiven Matrix is not Upper triangular");


}
void mul(int a[4][4],int b[4][4],int cc[4][4])
{
	int i,j,k;
	for(i=0;i<r;i++)
	{
		  for(j=0;j<c;j++)
		   {
				cc[i][j]=0;
				for(k=0;k<c;k++)
				{
					cc[i][j]=cc[i][j]+a[i][k]*b[k][j];
				}
			}
	  }
}

void saddle(int a[4][4])
 {
	int i,m,j,min=a[0][0],col=0,flag,flag1=0;
	for(i=0;i<r;i++)
	{
	  flag=0;
	  min=a[i][0];
	  for(j=1;j<c;j++)
	  {
		if(a[i][j]<min)
		{
			min=a[i][j];
			col=j;
		}
	 }

	 for(m=0;m<r;m++)
	  {
		if(a[m][col]>min)
		{     flag=0;
			  break;
		}
		else
			flag=1;
	 }
			if(flag==1)
				printf("\n\n\n\t\t Saddle point exist at (%dth row ,%dth column) with value as %d",i+1,col+1,min);
			else
				flag1++;


	}
	if(flag1>=r)
		printf("\n\n\n\t\tSaddle point does not exist ");

}

