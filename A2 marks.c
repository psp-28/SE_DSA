#include<stdio.h>
#define MAX 30

int main()
{
		int student_roll[MAX],student_marks[MAX];
		char status[MAX];
		int n,i;
		int cnt=0;
		float avg,total=0;
		
		
		printf("\n\t-----------------------------------------------------------");
		printf("\n\n\n Enter number of the students:");
		scanf("%d",&n);
		printf("Enter the roll number and the marks of DSA");
		printf("\n\n\n\t\t\t *********NOTE********");
		printf("\n\n # please enter -1 for the absent students #");
		
		
		for(i=0;i<n;i++)
		{
			printf("\n\n Enter the roll numbers:");
			scanf("%d",&student_roll[i]);
			
			printf("\n\n Enter the marks for roll number %d:",student_roll[i]);
			scanf("%d",&student_marks[i]);
			
		if(student_marks[i]>=40)
			status[i]='P';
			
			
		else if(student_marks[i]<40 && student_marks[i]>=0)
		        status[i]='F';
		        
		else
			status[i]='A';
	}
	
	printf("\n\n\t---------------------------------------------------------------");
	printf("\n\n\t*****************************Result*************************");
	printf("\n\n\t~Marks above 40 are pass,and below 40 are fail.The marks '-1' shows the students was absent for the test:");
	printf("\n\n\t................................................................");
	printf("\n\n\t\t Roll NO.\t\t Marks Obtained\t\t Status");
	printf("\n\n\t--------------------------------------------------------------");
	
	for(i=0;i<n;i++)
	{
		printf("\n\n\t\t%d \t\t\t%d \t\t\t\t%c \n",student_roll[i],student_marks[i],status[i]);
	}
	
		for(i=0;i<n;i++)
		{
			if(student_marks[i]>-1)
			{
				total +=student_marks[i];
				cnt++;
			}
		}
		
		avg=total/cnt;
		
		printf("\n\n\t\t1.Average score of the class is:%f",avg);
		
		int min,max;
		min=student_marks[0];
		max=student_marks[0];
		
		
		for(i=0;i<n;i++)
		{
			if(student_marks[i]<min && student_marks[i]>-1)
			
			min=student_marks[i];
		}
		
		for(i=0;i<n;i++)
		{
			if(student_marks[i]>max)
			
			max=student_marks[i];
		}
		
		printf("\n\n\t2.Heigest score of the class:%d",max);
		printf("\n\n\tlowest score of the calss:%d",min);
		
		
		printf("\n\n\t3.The DSA marks are \n\n\t List of the students who has scored the marks above average:");
		printf("\n\n...........................................................");
		printf("\n\n\t Roll no. \n\n\t marks");
		
		for(i=0;i<n;i++)
		{
			if(student_marks[i]>=avg)
			printf("\n\n\t %d \t\t\t %d",student_roll[i],student_marks[i]);
		}
		printf("\n\n..............................................................");
								   
								        		
		cnt=0;
		printf("\n\n\t Roll numbers of the absent students are:");
		
		for(i=0;i<n;i++)
		{
			if(student_marks[i]<=-1)
			{
				printf("::%d",student_roll[i]);
				cnt++;
			}
		}
	}				
