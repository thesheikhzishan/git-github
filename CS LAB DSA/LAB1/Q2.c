#include<stdio.h>
void print_lines(int i)
{
	if(i == 0)
		return;
	else
	{
		printf("* ");
		print_lines(i - 1);
	}
}
void printspaces(int i)
{
	if(i == 0)
		return;
	else
	{
		printf(" ");
		printspaces(i - 1);
	}
}
void print_pattern(int n, int i)
{
	if(n == 0)
		return;	
	printspaces(i);	
	print_lines(n);
	printf("\n");
	print_pattern(n - 1, i + 1);
	
}

void main()
{
	int n;
 	scanf("%d", &n);
	print_pattern(n , 0);
}
