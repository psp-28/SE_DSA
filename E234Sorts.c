/*
 * E35.c
 *
 *  Created on: 20-Sep-2016
 *      Author: pvpit
 */


#include<stdio.h>


void bubble(int ele[15],int no);
void quick(int[],int,int);
int partition(int[],int,int);
void insertion(int ele[15],int no);
void selection(int ele[15],int no);
void merge(int[],int,int,int);
void merge_sort(int[],int,int);

int main()
{
	int no,ele[15],i,ch;

	printf("\n\n\t\tEnter total no of Elements\t");
	scanf("%d",&no);

	for(i=0;i<no;i++)
	{
		printf("\n\n\t\tEnter the element\t");
		scanf("%d",&ele[i]);
	}
	do
	{
       

		printf("\n\n\n\n\t\t-----------------Sorting------------------------ \n\n");
		printf("\n\t\t1.Bubble Sort\n\n\t\t2.Insertion Sort\n\n\t\t3.Selection Sort");
		printf("\n\n\t\t4.Quick Sort\n\n\t\t5.Merge Sort\n\n\t\t6.Exit\n");
		printf("\n\n\t\tEnter your choice\t\n\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n\n\n\n\t\t-----------------Bubble Sorting------------------------ \n\n");
				bubble(ele,no);

					break;
			case 2:
				printf("\n\n\n\n\t\t-----------------Insertion Sorting------------------------ \n\n");
				insertion(ele,no);

					break;
			case 3:

				printf("\n\n\n\n\t\t-----------------Selection Sorting------------------------ \n\n");
					selection(ele,no);

					break;
			case 4:
				printf("\n\n\n\n\t\t-----------------Quick Sorting------------------------ \n\n");
					quick(ele,0,no-1);
					printf("\nSorted array is :");
					for(i=0;i<no;i++)
					printf("%d\t",ele[i]);
					break;
			case 5:
				printf("\n\n\n\n\t\t-----------------Merge Sorting------------------------ \n\n");
					merge_sort(ele,0,no-1);
					break;



		}

	}  while(ch<6);

return (0);

}
void bubble(int a[15],int no)
{
	int i,j,temp,k,no1;
	no1=no-1;
	printf("\n\n\n\t\t Before sorting \t\n\n\n");
			 for(i=0;i<no;i++)
			{
				printf("\t%d",a[i]);
			}
	printf("\n\n\n");
	printf("\n--------------------------------------------------------");

	for(i=0;i<no;i++)
	{
		for(j=0;j<no1;j++)
		{
			if(a[j]>a[j+1])
			{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}

		}
		printf("\n\nAfter pass %d:- ",i+1);
		for(k=0;k<no;k++)
		{
			printf("\t%d",a[k]);
		}
		no1--;
	}
	printf("\n\n--------------------------------------------------------");
	printf("\n\n\n After sorting\t\n\n\n");
	 for(i=0;i<no;i++)
	 {
		printf("\t%d",a[i]);

	}

}
void insertion(int a[15],int no)
{
	int i,j,temp,k;

	printf("\n\n\n\t\t Before sorting \t\n\n\n");
			 for(i=0;i<no;i++)
			{
				printf("\t%d",a[i]);
			}
		printf("\n\n\n");
	printf("\n--------------------------------------------------------");
	for(i=1;i<no;i++)
	{
		temp=a[i];
		j=i;
		while(j>0 && (a[j-1]>temp))
		{
			a[j]=a[j-1];
			j=j-1;
		}
		a[j]=temp;

		printf("\n\nAfter pass %d:-",i);
		for(k=0;k<no;k++)
		{
			printf("\t%d",a[k]);
		}
	 }
	printf("\n\n--------------------------------------------------------");
	printf("\n\n\n After sorting\t\n\n\n");
	 for(i=0;i<no;i++)
	 {
		printf("\t%d",a[i]);

	}

}
void selection(int a[15],int no)
{
	int i,j,temp,k;
	printf("\n\n\n\t\t Before sorting \t\n\n\n");
			 for(i=0;i<no;i++)
			{
				printf("\t%d",a[i]);
			}
	printf("\n\n\n");
	printf("\n\n--------------------------------------------------------");
	for(i=0;i<no;i++)
	{
		for(j=i+1;j<no;j++)
		{
			if(a[i]<a[j])
			{
			temp=a[j];
			a[j]=a[i];
			a[i]=temp;
		}

		}
		printf("\n\tAfter pass %d:- ",i+1);
		for(k=0;k<no;k++)
		{
			printf("\t%d",a[k]);
		}

	}
	printf("\n\n--------------------------------------------------------");
	printf("\n\n\n After sorting\t\n\n\n");
	 for(i=0;i<no;i++)
	 {
		printf("\t%d",a[i]);

	}

}

 void quick(int a[],int l,int u)
{
	int j;
	if(l<u)
	{
		j=partition(a,l,u);
		quick(a,l,j-1);
		quick(a,j+1,u);
	}
}
int partition(int a[],int l,int u)
{
	int key,i,j,temp;

	key=a[l];
	i=l;
	j=u+1;
	do
	{
		do
			i++;
		while(a[i]>key && i<=u);

		do
			j--;
		while(a[j]<key);

		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}while(i<j);

	a[l]=a[j];
	a[j]=key;
	return(j);
}

void merge_sort(int a[],int i,int j)
{
	int k;
	if(i<j)
	{
		k=(i+j)/2;
		merge_sort(a,i,k);
		merge_sort(a,k+1,j);
		merge(a,i,k,j);
	}
}
void merge(int a[],int l,int m,int u)
{
	int c[15];
	int i,j,k;

	i=l;
	j=m+1;
	k=0;
	while(i<=m && j<=u)
	{
		if(a[i] < a[j])
		{
			c[k]=a[i];
			k++;i++;
		}
		else
		{
			c[k]=a[j];
			k++;j++;
		}
	}
	while(i<=m)
	{
		c[k]=a[i];
		i++;k++;
	}
	while(j<=u)
	{
		c[k]=a[j];
		k++;j++;
	}
	for(i=l,j=0;i<=u;i++,j++)
		a[i]=c[j];
}


