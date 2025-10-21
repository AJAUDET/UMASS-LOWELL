#include <stdio.h>
#include "my_string.h"

int main(int argc, char* argv[])
{
	MY_STRING string[100];
	int i;

	for(i = 0; i < 100; i++)
	{
		string[i] = NULL;
	}

	string[0] = my_string_init_c_string("COPY ME!");

	for(i = 1; i < 100; i++)
	{
		string[i] = my_string_init_copy(string[0]);
	}

	my_string_destroy(&string[0]);
	string[0] = my_string_init_c_string("FIRST FIFTY!");

	for(i = 0; i < 50; i++)
	{
		my_string_assignment(&string[i], string[0]);
	}

	for(i = 0; i < 50; i++)
	{
		my_string_swap(string[i], string[99 - i]);
	}

	for(i = 0; i < 100; i++)
	{
		if(string[i] != NULL)
		{
			my_string_insertion(string[i], stdout);
			printf("\n");
			my_string_destroy(&string[i]);
		}
	}

	return 0;
}
