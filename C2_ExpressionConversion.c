/* Assignment No.C25

 * Implement C++ program for expression conversion as infix to postfix and its evaluation
using stack based on given conditions

i. Operands and operator, both must be single character.
ii. Input Postfix expression must be in a desired format.
iii. Only '+', '-', '*' and '/ ' operators are expected.

 */


#include<stdio.h>

#include<ctype.h>
#define MAX 50

typedef struct stack
{
	char data[MAX];
	int top;
}stack;


char pop(stack *);
void push(stack *,char);
int priority(char);

int main()
{
	stack s;
	char infix[MAX];
	char postfix[MAX];
	char token,ch;
	int i=0,j=0;
	s.top=-1;

	printf("\n\n\n\t\tEnter the INFIX expression:");
    scanf("%s",infix);
	while(infix[i]!='\0')
	{
		if(isalnum(infix[i]))
				{
					postfix[j]=infix[i];
					j++;
				}
		else
			if(infix[i] == '(')
			{
				push(&s,'(');

			}
		else
			if(infix[i] == ')')
			{
				token=pop(&s);
				while(token!='(')
				{
					postfix[j]=token;
					j++;
					token=pop(&s);
				}
			}
		else
		{
				while(priority(infix[i])<=priority(s.data[s.top]) && s.top!=-1)
				{
						token=pop(&s);
						postfix[j]=token;
						j++;
				}
				push(&s,infix[i]);

		}
		i++;
	}
	while(s.top!=-1)
		{
			token=pop(&s);
			postfix[j]=token;
			j++;
		}
	postfix[j]='\0';
	printf("\n\n\t\tconversion of infix to postfix\n\n\n\n");
	for(i=0;postfix[i]!='\0';i++)
		printf("%c",postfix[i]);

	return (0);
}

void push(stack *s,char x)
{
	s->top=s->top+1;
	s->data[s->top]=x;
}

char pop(stack *s)
{
	int x;
	if(s->top!=-1)
	{
		x=s->data[s->top];
		s->top=s->top-1;
		return(x);
	}
	else
		return('#');
}

int priority(char x)
{
	if(x == '(')
		return(0);
	if(x == '+' || x == '-')
		return(1);
	if(x == '*' || x == '/' || x == '%')
		return(2);
	return(3);
}
