
//Headers files

#include<string.h>
#include<stdio.h>


int length(char []);
void reverse(char []);
void reverse1(char []);
char* reverse2(char []);
void palindrome(char []);
void copy(char [],char []);
void compare(char [],char []);
void concat(char [],char []);
//void search(char [],char []);
void count(char []);

int main()
  {
	char *str,str1[100],str11[100];
	int result,op,ch;

	do
	 {

		printf("\n\n\n\t\t\t*** Menu ***");
		printf("\n\n\t---------------------------------------------\n");
		printf("\n\n\t1.Length of a string");
		printf("\n\n\t2.Reverse the Given String\n\n\t3.Check for palindrome\n\n\t4.Copy");
		printf("\n\n\t5.String Comparison\n\n\t6.String Concatenation\n\n\t7.String Searching");
		printf("\n\n\t8.Counting of Words,Characters & Special Characters\n\n\t9.Exit");
		printf("\n\n\t---------------------------------------------\n");
		printf("\n\n\tEnter Your Choice:  ");
		scanf("%d",&op);

		switch(op)
		{
			case 1:

					printf("\n\n\t Enter a String:");
					scanf("%s",str1);
					result=length(str1);
					printf("\n\n Length of %s is %d",str1,result);


					break;

			case 2:

					printf("\n\n\t Enter a String:");
					scanf("%s",str1);

					reverse(str1);
					printf("\n\n\tReverse string  %s",str1);

					reverse1(str1);
					printf("\n\n\tReverse string  %s",str1);

					str=reverse2(str1);
					printf("\n\n\tReverse string  %s",str);


					break;
			case 3:

					printf("\n\n\t Enter a String:");
					scanf("%s",str1);
					palindrome(str1);

					break;
			case 4:

					printf("\n\n\t Enter a String:");
					scanf("%s",str1);
					copy(str11,str1);

					printf("\n\n\n\t\t\tString copy successfully!!!!\n\n\t\tString is  %s",str11);

					break;
			case 5:

					printf("\n\n\n\t\t Enter 1st string:");
					scanf("%s",str1);
					printf("\n\n\n\t\t Enter 2nd string:");
					scanf("%s",str11);
					compare(str1,str11);

					break;
			case 6:

					printf("\n\n\n\t\t Enter 1st string:");
					scanf("%s",str1);
					printf("\n\n\n\t\t Enter 2nd string:");
					scanf("%s",str11);
					concat(str1,str11);
					printf("\n\n\n\t\t Concate String is  %s",str1);


					break;
		   /*	case 7:
					printf("\n Enter 1st string:");
					gets(a);
					printf("\n Enter 2nd string:");
					gets(b);
					search(a,b);

					getch();break; */
			case 8:

					printf("\n\n\n\t\t Enter a string:  ");
					fgets(str1,100,stdin);
					//scanf("%s",str1);
					count(str1);
					break;



		}
		printf("\n\n\n\t\tWant to continue? \t");

		scanf("%d",&ch);

		if(ch==0)
			break;

	   }while(op<9);
	return (0);
  }

int length(char str[])
  {
	int count=0,i=0;

	while(str[i] !='\0')
	{
		count++;
		i++;
	}
	return(count);
  }
void reverse(char s[])
   {
	   int i,j=length(s);

		char m;
		j--;

		for(i=0;i<j;i++)
		{
			m=s[i];
			s[i]=s[j];
			s[j]=m;

			j--;
		}


	}
void reverse1(char s[])
   {
	   int i,j=length(s),k;
	   char temp[100];
	   temp[j]='\0';
	   j--;

		for(i=0;s[i]!='\0';i++)
		{
			 temp[j]=s[i];
			 j--;
		}

	   i=0;
	   while(temp[i]!='\0')
	   {
			s[i]=temp[i];
			i++;
	   }
	   s[i]='\0';

}
char* reverse2(char s[])
   {
	   int i,j=length(s),k;
		char temp[100];
		temp[j]='\0';
		j--;

		for(i=0;s[i]!='\0';i++)
		{
			 temp[j]=s[i];
			 j--;
		}

	   return(temp);

	}
void  palindrome(char str1[])
  {
	int i,j,flag=0;

	 i=j=0;
	 j=length(str1);
	 j--;
	  while(i<j)
	   {
			if(str1[i]!=str1[j])
			{
				flag=0;
				break;
			}
			else
				flag=1;
			i++;j--;
	   }
	  if(flag==0)
			printf("\n\n\n\t\tNot a palindrome");
	  else
			printf("\n\n\n\t\tA palindrome");
	 }
void copy(char ans[],char source[])
{
	int i=0;
	   while(source[i]!='\0')
	   {
			ans[i]=source[i];
			i++;
	   }
	   ans[i]='\0';
}

void compare(char str1[],char str11[])
{
	 int i,j,flag,n=0;
	 i=length(str1),j=length(str11);
	  if(i!=j)
	  {
			if(i>j)
				printf("\n\n\n\t\tSting %s is greater of & %s",str1,str11);
			else
				printf("\n\n\n\t\tSting %s is Substring of & %s",str1,str11);
	  }
	  else
	  {
		while(str1[n]!='\0')
		{
			if(str1[n]==str11[n])
				flag=1;
			else
			{
				flag=0;
				break;
			}
			n++;
		}
		if(flag==1)
		{
		  printf("\n\n\n\t\tSting %s is equal to %s",str11,str1);
		}
		else
		printf("\n\n\n\t\tSting %s is not equal to  %s",str11,str1);
	  }
}
 void concat(char str1[],char str11[])
   {
	int i,j,n;
	i=length(str1);
		for(j=i,n=0;str11[n]!='\0';j++,n++)
			str1[j]=str11[n];
		str1[j]='\0';
  }
 void count(char str1[])
  {
	int words=0,characters=0,spchar=0,i;
	int alpha=0,lower=0,upper=0,digit=0;

	for(i=0;str1[i]!='\0';i++)
	{
		if(isalnum(str1[i]) && (i==0 || !isalnum(str1[i-1])))
			words++;
	   if(!isalnum(str1[i]) && !isspace(str1[i]))
			 spchar++;
	   if(isalpha(str1[i]))
	   {
			alpha++;
			if(islower(str1[i]))
				lower++;
			else
				upper++;
	   }
	   if(isdigit(str1[i]))
			digit++;


	  characters++;
	}
	printf("\n\n\n\t\t no of characters       \t%d",characters);
	printf("\n\n\t\t no of special characters  \t%d",spchar);
	printf("\n\n\t\t no of words               \t%d",words);
	printf("\n\n\t\t no of alphabets           \t%d",alpha);
	printf("\n\n\t\t no of lowercase letters   \t%d",lower);
	printf("\n\n\t\t no of upperercase letters \t%d",upper);
	printf("\n\n\t\t no of digits letters      \t%d",digit);
  }
