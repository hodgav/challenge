#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "challenge.h"

char** str_cpy(char** dest, const char* src)
{
    char* tempBuffer=NULL;
    tempBuffer=(char*)malloc(strlen(src)+1);
    strcpy(tempBuffer,src);
    free(*dest);
    *dest=tempBuffer;
	return dest;
}


char** str_cat(char** dest, const char* src) 
{
    int destLength,srcLength=strlen(src);
    char* tempBuffer=*dest;
    if (tempBuffer==NULL) 
    {
      tempBuffer=(char*)malloc(srcLength+1);
      strcpy(tempBuffer,src);
	  *dest=tempBuffer;
	  return dest;
    }
      destLength=strlen(*dest);
      tempBuffer=(char*)realloc(tempBuffer,destLength+srcLength+2);
      strcat(tempBuffer,src);
      strcat(tempBuffer,"!");
	  *dest=tempBuffer;
	  return dest;
}
