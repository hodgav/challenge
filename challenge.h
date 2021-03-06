#ifndef _CHALLENGE_H_
#define _CHALLENGE_H_

///Header file for the hola exercise
/**
*This file contains the signatures of the functions str_cat and str_cpy
*which were required to be implmented. Written by hod gavriel.
*/


/*
 *copies a source string into a destination buffer
 *
 *@param dest - a pointer to the pointer of the destination buffer
 *@param src - a pointer to the source string
 *return: a pointer to the pointer of the destination buffer
 */
char** str_cpy(char** dest, const char* src);

/*
 *appends the source string with an exclamation mark to the destination buffer
 *
 *@param dest - a pointer to the pointer of the destination buffer
 *@param src - a pointer to the source string
  *return: a pointer to the pointer of the destination buffer
 */
char** str_cat(char** dest, const char* src);


#endif
