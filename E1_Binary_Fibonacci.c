
/*
 *Assignment no.E32
Write C++ program to store roll numbers of student in array who attended training program
in random order. Write function for-
a) Searching whether particular student attended training program or not using linear search
and sentinel search. b) Searching whether particular student attended training program or
not using binary search and Fibonacci search.

 */
#include<stdio.h>


void bubble_sort(int [],int);
void bin_search(int [],int,int);
void bin_searchR(int [],int,int,int);
void linear_search(int [],int,int);
int main()
{
	int a[30],n,i,key,result,ch;

	do{


			printf("\n\n\n\n\t\t-----------------Searching------------------------ \n\n");
			printf("\n\t\t1.Linear search\n\n\t\t2.Binary search\n\n\t\t3.Binary search with recursion\n\n\t\t3.Exit\n");
			printf("\n\n\t\tEnter your choice\t\n\n");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:

					printf("\n\n\t--------------------------------------------------------------------");
					printf("\n\n\n\n\t\t*** Linear search *** \n\n");
					printf("\n\n\t--------------------------------------------------------------------");

					printf("\n\n\t\tEnter number of student attended training program :");
							scanf("%d",&n);

							printf("\n\n\t\tEnter the roll numbers of student :");
							for(i=0;i<n;i++)
								scanf("%d",&a[i]);

							printf("\n\n\t\tEnter the roll number to Searching whether particular student attended training program or not :");
							scanf("%d",&key);

					linear_search(a,key,n);

						break;
				case 2:
					printf("\n\n\t--------------------------------------------------------------------");
					printf("\n\n\n\n\t\t*** Binary search *** \n\n");
					printf("\n\n\t--------------------------------------------------------------------");

					printf("\n\n\t\tEnter number of student attended training program :");
							scanf("%d",&n);

							printf("\n\n\t\tEnter the roll numbers of student :");
							for(i=0;i<n;i++)
								scanf("%d",&a[i]);

							printf("\n\n\t\tEnter the roll number to Searching whether particular student attended training program or not :");
							scanf("%d",&key);

					bin_search(a,key,n);

						break;
				case 3:
					printf("\n\n\t--------------------------------------------------------------------");
					printf("\n\n\n\n\t\t*** Binary search with Recursion *** \n\n");
					printf("\n\n\t--------------------------------------------------------------------");

					printf("\n\n\t\tEnter number of student attended training program :");
							scanf("%d",&n);

							printf("\n\n\t\tEnter the roll numbers of student :");
							for(i=0;i<n;i++)
								scanf("%d",&a[i]);

							printf("\n\n\t\tEnter the roll number to Searching whether particular student attended training program or not :");
							scanf("%d",&key);
					bubble_sort(a,n);
					bin_searchR(a,key,0,n);

						break;
			}
		}  while(ch<4);



return(0);

}
void bubble_sort(int a[],int n)
{
	int i,j,temp;

	for(i=1;i<n;i++)
		for(j=0;j<n-i;j++)
			if(a[j]>a[j+1])
			{
				   temp=a[j];
				   a[j]=a[j+1];
				   a[j+1]=temp;
			}
}
void bin_search(int a[],int key,int n)
{
	int i,j,c,k;
	bubble_sort(a,n);
	i=0;
	j=n-1;
	c=(i+j)/2;
//while(i<=j)
	for(k=0;k<=n+1;k++)
	{
		 if(key>a[c])
			i=c+1;
		 if(key<a[c])
			j=c-1;
		 if(key==a[c])
		 break;
	c=(i+j)/2;
	}
	if(k<=n)
	 printf("\n\n\n student attended training program ");
	else
	printf("\n student not attended training program");
}
void bin_searchR(int a[],int key,int l ,int u )
{
	int mid;
	mid=(u+l)/2;
	if(l<=u)
	{	
		 if(key==a[mid])
			printf("\n\n\n student attended training program ");
		 if(key>a[mid])
			bin_searchR(a,key,mid+1,u);
		 if(key<a[mid])
			bin_searchR(a,key,0,mid-1);
	}
	else
		printf("\n student not attended training program");
}

/*void search(int a[],int key,int n)
{
	int i;
	i=0;
	
	for(i=0;i<=n+1;i++)
	{
		if(a[i]==key)
		 break;
	}
	if(i<=n)
		printf("\n\n\n student attended training program ");
	else
		printf("\n student not attended training program");

}*/
void linear_search(int a[],int key,int n)
{
	int i,flag;
	i=0;
	
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		{
			printf("\n\n\n student attended training program ");
			flag=1;
			 break;
		}
		else
			flag=0;
	}
	if(flag==0)
		
		printf("\n student not attended training program");

}



