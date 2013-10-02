#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void str_cpy(char** dest, char* src)
{
    char* tempBuffer=NULL;
    if((tempBuffer=(char*)malloc(strlen(src)+1))!=NULL)
        strcpy(tempBuffer,src);
    else
        fprintf(stderr,"Error: malloc failed! (str_cpy)\n");
    free(*dest);
    *dest=tempBuffer;	
}


void str_cat(char** dest, char* src) 
{
    int destLength,srcLength=strlen(src);
    char* tempBuffer=*dest;
    if (tempBuffer==NULL) 
    {
      if((tempBuffer=(char*)malloc(srcLength+1))!=NULL)
          strcpy(tempBuffer,src);
      else
          fprintf(stderr,"Error: malloc failed! (str_cat)\n");
    }
    else
    {
      destLength=strlen(*dest);
      if((tempBuffer=(char*)realloc(tempBuffer,destLength+srcLength+2))!=NULL)
      {
        strcat(tempBuffer,src);
        strcat(tempBuffer,"!");
      }
      else
        fprintf(stderr,"Error: realloc failed! (str_cat)\n");
    }
}

int main(int argc, char *argv[])
{
    char *s = NULL;
    str_cpy(&s, "Hola Hola");
    str_cpy(&s, s+5);
    str_cat(&s, " World");
    puts(s); /* result should be: "Hola World!" */
}
