#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX_EXPRESSIONS 25
char user_input[MAX_EXPRESSIONS];
int input_count;
struct Stack
{
	int top;
	unsigned capacity;
	int *array;
};
struct Stack *createStack(unsigned capacity);
int isEmpty(struct Stack *stack);
void push(struct Stack *stack, char op);
int evaluatePostfixExpression(char *exp);
int main(int argc, char *argv[])
{
	// Check for invalid usage
	if (argc < 3)
	{
		printf("Usage: enter at least 2 arguments to be evaluated...\n");
		return 1;
	}
	
	input_count = argc - 1;
	
	if (input_count > MAX_EXPRESSIONS)
	{
		printf("Maximum number of expressions is %i\n", MAX_EXPRESSIONS);
		return 2;
	}
	
	for (int i = 0; i < input_count; i++)
	{
		user_input[i] = argv[i + 1][0];
		//printf("Source array: %c\n", user_input[i]);
	}
	
	char ans = evaluatePostfixExpression(user_input);
	//printf("Func output: %c\n", ans);
	if (ans == 'F')
	{
		printf("%s\n", "FALSE");
	}
	else
	{
		printf("%s\n", "TRUE");
	}
}

struct Stack *createStack(unsigned capacity)
{
	struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
	if (!stack)
		return NULL;
	stack->top = -1;
	stack->capacity = capacity;
	stack->array = (int *)malloc(stack->capacity * sizeof(int));
	
	if (!stack->array)
		return NULL;
	return stack;
}

int isEmpty(struct Stack *stack)
{
	return stack->top == -1;
}

char pop(struct Stack *stack)
{
	if (!isEmpty(stack))
		return stack->array[stack->top--];
	return '$';
}

void push(struct Stack *stack, char op)
{
	stack->array[++stack->top] = op;
}

int evaluatePostfixExpression(char *exp)
{
	//For this excerice I just took the first character of each input in the array and used that as
	// the operand rather than a string of characters. The array is scanned and if the first char of the argument is 'T'
	// is taken to be "TRUE". 'F' is FALSE, 'O' is OR, 'A' is AND, and 'N' is NOT. And while this does
	// logically work it also mean that the user could enter "T F A" and the output would be false
	
	struct Stack *stack = createStack(strlen(exp));
	int i;
	
	if (!stack)
		return -1;
		
	// check all characters one by one
	
	for (i = 0; exp[i]; ++i)
	{
		// If the scanned character is an operand
		// push it to the stack.
		
		if ((exp[i] == 'T') || (exp[i] == 'F'))
			push(stack, exp[i]);
			
		// If the scanned char is an operator, pop two
		// elements from stack and apply the operator
		else
		{
			char val1 = pop(stack);
			char val2 = pop(stack);
			char val3 = 'T';
			char val4 = 'F';
			
			switch (exp[i])
			{
			case 'A':
				if ((val1 == 'T') && (val2 == 'T'))
					push(stack, val3);
				else
					push(stack, val4);
				break;
			case 'O':
				if ((val1 == 'T') || (val2 == 'T'))
					push(stack, val3);
				else
					push(stack, val4);
				break;
			case 'N':
				if ((val1 == 'T') || (val2 == 'T'))
					push(stack, val4);
				else if ((val1 == 'F') || (val2 == 'F'))
					push(stack, val3);
				break;
			}
		}
	}
	return pop(stack);
}
