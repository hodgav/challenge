#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void str_cpy(char** s, char* t) 
{
    char* tempBuffer=NULL;    
    if((tempBuffer=(char*)malloc(strlen(t) + 1))!=NULL)
        strcpy(tempBuffer,t);
    else
        fprintf(stderr,"Error: malloc failed! (str_cpy)\n");
    if (*s!=NULL) 
        free(*s);
    *s=tempBuffer;	
}

void str_cat(char** s, char* t) 
{
    char* tempBuffer=NULL;
    if (*s==NULL) 
    {
        if((*s=(char*)malloc(strlen(t)+1))!=NULL)
            strcpy(*s,t);
	else
            fprintf(stderr,"Error: malloc failed! (str_cat)\n");
    }
    else
    {
        if((tempBuffer = (char*)malloc(strlen(*s)+strlen(t)+2))!=NULL)
        {
            tempBuffer[0]='\0';
            strcat(tempBuffer,*s);
            strcat(tempBuffer,t);
            strcat(tempBuffer,"!");
            free(*s);
            *s=tempBuffer;
        }
	else
            fprintf(stderr,"Error: malloc failed! (str_cat)\n");
    }
}

int main(int argc, char *argv[])
{
    char *s = NULL;
    str_cpy(&s, "Hola Hola");
    str_cpy(&s, s+5);
    str_cat(&s, " World");
    puts(s); /* result should be: "Hola World!" */ //it worked for me (hod)
    return 0;
}
