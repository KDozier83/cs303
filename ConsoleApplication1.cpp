#include <stdio.h>
#include <stdafx.h>
#include <iostream>
#define CSIS 303

using namespace std;

void push(int *myStack, int* myTop, int myItem)
{
	printf("Pushing : %d ", myItem);
	myStack[*myTop] = myItem;
	(*myTop)++;
}
int pop(int *myStack, int* myTop)
{
	int myTemp;
	(*myTop)--;
	myTemp = myStack[*myTop];
	printf("Popping : %d", myTemp);
	return myTemp;
}
void calc(int* myNumStack, int* myNumTop, int* myOpStack, int* myOpTop)
{
	int n1, n2, a;
	char s;
	n2 = pop(myNumStack, myNumTop);
	n1 = pop(myNumStack, myNumTop);
	switch (pop(myOpStack, myOpTop))
	{
	case '+': a = n1 + n2; s = '+'; break;
	case '-': a = n1 - n2; s = '-'; break;
	case '*': a = n1 * n2; s = '*'; break;
	case '/': a = n1 / n2; s = '/'; break;
	}
	printf("%d, %c, %d = %d \n", n1, s, n2, a);
	push(myNumStack, myNumTop, a);
	while (getchar()!= '\n') {
	}
}
int main(void)
{
	int myOpTop = 0, myNumTop = 0, i = 0, myNumStack[50], myOpStack[30];
	char myStr[102], ch;

	printf("Enter Infix Expression: ");
	fgets(myStr, 100, stdin);
	while (myStr[i] != '\n') {i++;}
	myStr[i] = '\0';
	printf("\nString : %s \nStack Length : %d", myStr, i);
	i = 0;
	while ((ch = myStr[i]) != '\0')
	{
		printf("\nReading : %c ", myStr[i]);
		if (ch == '(') { i++; continue; }
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
			push(myOpStack, &myOpTop, ch);
		else if (ch >= 48 && ch <= 57)
			push(myNumStack, &myNumTop, (ch-48));
		else if (ch == ')')
			calc(myNumStack, &myNumTop, myOpStack, &myOpTop);
		else printf("\n%c is not valid\n", ch); i++;
	}
	printf("\nAnswer : %d\n", pop(myNumStack, &myNumTop));
	getchar();

	cout << endl;
	system("pause");
	return 0;
}