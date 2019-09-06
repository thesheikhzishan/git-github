/*
	gcc -o shift Q1.c
	./shift <in1>out1

	char line[20]
	fgets(line, sizeof(line), stdin)	
	sscanf(line, "%d", &n)
*/

#include<stdio.h>
void ShiftArrayElements(int a[], int n)
{
	int temp = a[n - 1];
	int i;	
	for(i = n - 1; i >= 1; i--)
		if(a[i - 1] > temp)			
		{		
			a[i] = a[i - 1];
		}
		else
			break;
	a[i] = temp;
}
void main()
{
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i =0; i < n; i++)
		scanf("%d", &a[i]);

	ShiftArrayElements(a, n);

	for(int i = 0; i < n; i++)
		printf("%d\n", a[i]);
}
