#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

int main(int argc, char* argv[])
{
  MY_STRING hMy_string = NULL;
  FILE* fp;
  
  hMy_string = my_string_init_default();
  fp = fopen("dictionary.txt", "r");

  // test if the file opened exit otherwise
  if(fp == NULL)
    {
      fprintf(stderr, "Error file not found\n");
      my_string_destroy(hMy_string);
    }

  while(my_string_extraction(hMy_string, fp) == SUCCESS)
    {
      // only print words __ characters long
      if(my_string_get_size(hMy_string) == 29)
	{
	  my_string_insertion(hMy_string, stdout);
	  printf("\n");
	}
    }
  
  my_string_destroy(&hMy_string);
  fclose(fp);
  return 0;
}
