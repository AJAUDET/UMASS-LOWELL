#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "my_string.h"

struct my_string
{
  int size;
  int capacity;
  char* data;
};
typedef struct my_string My_string;

MY_STRING my_string_init_default(void)
{
  // cast to the known type
  My_string* pString = (My_string*)malloc(sizeof(My_string));
  if(pString == NULL)
  {
    return NULL;
  }

  pString->size = 0;
  pString->capacity = 7;
  pString->data = malloc(sizeof(char) * pString->capacity);
  if(pString->data == NULL)
    {
      free(pString);
      return NULL;
    }
  // set first character to the NULL Terminator char
  pString->data[0] = '\0';
  return (MY_STRING)pString;
}

void my_string_destroy(MY_STRING* phMy_string)
{
  // test if the string is the same
  if(phMy_string && *phMy_string)
    {
      My_string* pString = (My_string*)*phMy_string;
      free(pString->data);
      free(pString);
      *phMy_string = NULL;
    }
}

MY_STRING my_string_init_c_string(const char* c_string)
{
  // test if the string is valid
  if(c_string == NULL)
    {
      return NULL;
    }

  // length is the length of the c_string
   int length = strlen(c_string);
   My_string* pString = (My_string*)malloc(sizeof(My_string));
   if(pString == NULL)
     {
       return NULL;
     }
   
   pString->capacity = length +1;
   pString->size = length;
   pString->data = malloc(sizeof(char) * pString->capacity);
   if(pString->data == NULL)
     {
       free(pString);
       return NULL;
     }
   strcpy(pString->data, c_string);
   return (MY_STRING)pString;
}

int my_string_get_capacity(MY_STRING hMy_string)
{
  if(hMy_string == NULL)
    {
      return 0;
    }
  My_string* pString = (My_string*)hMy_string;
   return pString->capacity;
}

int my_string_get_size(MY_STRING hMy_string)
{
    if(hMy_string == NULL)
    {
      return 0;
    }
  My_string* pString = (My_string*)hMy_string;
   return pString->size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
{
  ;  if(hLeft_string == NULL || hRight_string == NULL)
    {
      return 0;
    }
  My_string* hLeft = (My_string*)hLeft_string;
  My_string* hRight = (My_string*)hRight_string;

  return strcmp(hLeft->data,hRight->data);
}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp)
{
    My_string* pString = (My_string*)hMy_string;
    int chr;
    int read_chr = 0;

    // before we start reset size to 0
    pString->size = 0;

    // test if the character is a space or a regular char / EOF to skip white space
    while(isspace(chr = fgetc(fp)) && chr != EOF);

    // test if character is EOF
    if(chr == EOF)
      return FAILURE;

    // test if character is not EOF and that the char is not a space
    if(chr != EOF &&  !isspace(chr))
      {
	pString->data[pString->size++] = chr;
        read_chr++;
      }

      // test each following character
      while((chr = fgetc(fp)) != EOF && !isspace(chr))
	{
	  // if there is more size  than capacity double capacity
	  if(pString->size >= pString->capacity)
	    {
	      pString->capacity *= 2;
	      char* temp = realloc(pString->data, pString->capacity);

	      pString->data = temp;
	    }
	  
	  pString->data[pString->size++] = chr;
	  read_chr++;
	}
      if(isspace(chr))
	{
	  ungetc(chr,fp);
	}
	pString->data[pString->size] = "\0";
	return (read_chr > 0) ? SUCCESS : FAILURE;
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp)
{
  My_string* pString = (My_string*)hMy_string;
  
  // we need to write the string data to the file
  int write = fwrite(pString->data, sizeof(char), pString->size, fp);

  // test if the word is outside of the size of our string
  if(write < pString->size)
    {
      return FAILURE;
    }
  return SUCCESS;
}

// from here to my_string_c_str are basically the same as the vector stuff with some modifs
Status my_string_push_back(MY_STRING hMy_string, char item)
{
    My_string* pString = (My_string*)hMy_string;
    char* temp_chr;
    int i;
    if(hMy_string == NULL)
      {
	return FAILURE;
      }
    if(pString->size >= pString->capacity)
      {
	temp_chr = (char*)malloc(sizeof(char) * pString->capacity);

	  if(temp_chr == NULL)
	    {
	      return FAILURE;
	    }
      }
    for(i = 0; i < pString->size; i++)
      {
	temp_chr[i] = pString->data;
      }
    free(pString->data);
    pString->data = temp_chr;
    pString->capacity *= 2;
    return SUCCESS;
}

Status my_string_pop_back(MY_STRING hMy_string)
{
      My_string* pString = (My_string*)hMy_string;
       if(hMy_string == NULL)
      {
	return FAILURE;
      }
        if(pString->size <= 0)
      {
	return FAILURE;
      }
	pString->size--;
	pString->data[pString->size]= '\0';
	return SUCCESS;
}

char* my_string_at(MY_STRING hMy_string, int index)
{
        My_string* pString = (My_string*)hMy_string;
      if(hMy_string == NULL)
      {
	return NULL;
      }
        if(index < 0 || index >= pString->size)
      {
	return NULL;
      }
	return &(pString->data[index]);
}

char* my_string_c_str(MY_STRING hMy_string)
{
   My_string* pString = (My_string*)hMy_string;
   char* temp_chr;
   int i;

   if(hMy_string == NULL)
   {
     return NULL;
   }
   if(pString->size >= pString->capacity)
   {
     temp_chr = (char*)malloc(sizeof(char) * pString->capacity);

     if(temp_chr == NULL)
       {
	 return NULL;
       }
     
     for(i = 0; i < pString->size; i++)
     {
       temp_chr[i] = pString->data[i];
     }
     free(pString->data);
     pString->data = temp_chr;
     pString->capacity++;
   }
   pString->data[pString->size] = '\0';
   return pString->data;
}
	
Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{
   My_string* pResult = (My_string*)hResult;
   My_string* pAppend = (My_string*)hAppend;
   
   char* temp_chr;
   int i;
   int tot_cap;

   // test if either are NULL
   if(hResult == NULL || hAppend == NULL)
     {
       return FAILURE;
     }
   
   tot_cap = pResult->capacity + pAppend->capacity;

   // test if the total size is outside of the capacity for the result
   if((pResult->size + pAppend->size) >= pResult->capacity)
     {
       temp_chr = (char*)malloc(sizeof(char) * tot_cap * 2);
       if(temp_chr == NULL)
	 {
	   return FAILURE;
	 }
       for(i =0; i < pResult->size; i++)
	 {
	   temp_chr[i] = pResult->data[i];
	 }
       free(pResult->data);
       pResult->data = temp_chr;
       pResult->capacity = tot_cap * 2;
     }

   // append the strings
   for(i = pResult->size; i < (pResult->size + pAppend->size); i++)
     {
       pResult->data[i] = pAppend->data[i - pResult->size];
     }
   pResult->size += pAppend->size;

   return SUCCESS;
}

 Boolean my_string_empty(MY_STRING hMy_string)
 {
   My_string* pString = (My_string*)hMy_string;
   return(pString->size == 0)? TRUE : FALSE;
 }
