#include <string>
#include <iostream>
#include <stack>
#include <cmath>
#include "pch.h"

using namespace std;

string infix2postfix(string a);
int infix(string a);
int postfix(string a);
int order(char op);
bool symbol(char sign);

int main(int argc, char const *argv[])
{
	string sample;
	sample = "1+(2-3(()";
	try 
	{
		cout << infix(sample) << endl;
	}
	catch (char const* z)
	{
		cerr << z << endl;
	}

	while (cin)
	{	
		getline(cin, sample);
		if (sample.size() == 0)
		{
			continue;
		}
		try
		{
			cout << infix(sample) << endl;
		}
		catch (char const* z) 
		{
			cerr << z << endl;
		}
	}
	return 0;
};

int infix(string a)
{
	return postfix(infix2postfix(a));
}

string infix2postfix(string a)
{
	string postfix;
	stack<char>stack;
	char previous;
	int openParens = 0;

	for (string::iterator it = a.begin(); it != a.end(); it++)
	{

		char sign = *it;
		if (isspace(sign))
		{
			continue;
		}
		if (isdigit(sign))
		{
			postfix.append(1, sign);
		}
		else if (sign == '(')
		{
			openParens++;
			stack.push(sign);
		}
		else if (symbol(sign))
		{
			if (stack.empty())
			{
				stack.push(sign);
			}
			else 
			{
				char op = stack.top();
				while (order(op) > order(sign))
				{
					stack.pop();
					postfix.append(1, op);
				}
				stack.push(sign);
			}
		}
		else if (sign == ')')
		{
			openParens--;
			while (!stack.empty() && stack.top() != '(')
			{
				postfix.append(1, stack.top());
				stack.pop();
			}
			if (!stack.empty())
			{
				stack.pop();
			}
		}
		else 
		{
			if (symbol(previous) || previous == '(' || previous == ')') 
			{

				throw "Expression Error! Try Again";
			}
			else
			{
				throw "Expression Error! Try Again";
			}
		}
		previous = sign;
	}
	if (openParens > 0)
	{
		throw "Enter infix expression: ";
	}

	while (!stack.empty()) 
	{
		postfix.append(1, stack.top());
		stack.pop();
	}
	return postfix;
}

int postfix(string a)
{
		stack<int>stack;
		for (string::iterator it = a.begin(); it != a.end(); it++)
		{
			char sign = *it;
			if (isdigit(sign))
			{
				stack.push(sign - '0');
			}
			else
			{
				int x = stack.top();
				stack.pop();
				int y = stack.top();
				stack.pop();
				int result;
				switch (sign)
				{
				case '+': result = y + x; break;
				case '-': result = y - x; break;
				case '*': result = y * x; break;
				case '/': result = y / x; break;
				case '^': result = (int)pow((double)y, x); break;
				}
				stack.push(result);
		}
	}
	return stack.top();
}

bool symbol(char sign)
{
	return sign == '+' || sign == '-' || sign == '*' || sign == '/' || sign == '^';

}

int order(char op)
{
	switch (op)
	{
	case '+': return 1;
	case '-': return 2;
	case '*': return 3;
	case '/': return 4;
	case '^': return 5;
	}
	return 0;
}