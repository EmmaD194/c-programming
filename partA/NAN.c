#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_EXPRESSIONS 25

char user_input[MAX_EXPRESSIONS];
int input_count;

unsigned char *compress_nan(char *input, int *result_length);
char *uncompress_nan(unsigned char *input, int input_length);
void compress(char *exp);

int main(int argc, char *argv[])
{
	// in order for the array to be scanned properly each value to be encoded/decoded needs to be separated by a space eg " G
	A T C"
	// Check for invalid usage
	if (argc < 3)
	{
		printf("Usage: Not enough arguments entered");
		return 1;
	}

	input_count = argc - 1;

	if (input_count > MAX_EXPRESSIONS)
	{
		printf("Maximum number of expressions is %i\n", MAX_EXPRESSIONS);
		return 2;
	}
	if (argv[1] == 'encode')
	{
		int count = input_count - 2;
		for (int i = 0; i < input_count; i++)
		{
			user_input[i] = argv[i + 2][0];
		}
	}
	else if (argv[1] == 'decode')
	{
		int count = input_count - 2;
		for (int i = 0; i < input_count; i++)
		{
			user_input[i] = argv[i + 2][0];
		}
	}
}

unsigned char *compress_nan(char *input, int *result_length)
{
	void compress(input);
}

char *uncompress_nan(unsigned char *input, int input_length)
{
	void uncompress(input);
}

void compress(char *exp)
{
	int i;
	for (i = 0; user_input[i]; ++i)
	{
		if (user_input[i] == 'G')
		{
			printf("%s\n", "00");
		}
		else if (user_input[i] == 'C')
		{
			printf("%s\n", "01");
		}
		else if (user_input[i] == 'A')
		{
			printf("%s\n", "10");
		}
		else if (user_input[i] == 'T')
		{
			printf("%s\n", "11");
		}
	}
}

void uncompress(char *exp)
{
	int i;
	for (i = 0; user_input[i]; ++i)
	{
		if (user_input[i] == '00')
		{
			printf("%c\n", "G");
		}
		else if (user_input[i] == '01')
		{
			printf("%c\n", "C");
		}
		else if (user_input[i] == '10')
		{
			printf("%c\n", "A");
		}
		else if (user_input[i] == '11')
		{
			printf("%c\n", "T");
		}
	}
}
