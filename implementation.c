#include "implementation.h"
#include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
#define MAX 4096
 
char* ReplaceSubtractives(char* originalstring)
{
    
    Replace(originalstring, "IIII", "IV"); //Replace Roman Subractive IIII=IV
    return originalstring;
}

/**
 * The replace function
 *
 * Searches all of the occurrences using recursion and replaces with the given string
 * Parameters: 
 * char * o_string : The original string
 * char * s_string : The search string to search for
 * char * r_string : The replace string
 */

void Replace(char * o_string, char * s_string, char * r_string) 
{
    char buffer[MAX]; //a buffer to execute replace 
    char * ch; // Store the pointer returned from strstr
    if(!(ch = strstr(o_string, s_string))) //exit condition
    return;
    strncpy(buffer, o_string, ch-o_string); //copy all the content before the first occurrence of the search string to buffer
    buffer[ch-o_string] = 0; //prepare the buffer for appending by adding a null to the end of it
    sprintf(buffer+(ch - o_string), "%s%s", r_string, ch + strlen(s_string)); //append using sprintf function
    o_string[0] = 0; //empty o_string for copying
    strcpy(o_string, buffer);
    return Replace(o_string, s_string, r_string);//pass recursively to replace other occurrences
 }
 
 char* add(char* ostring1, char* ostring2) {		
	strcat(ostring1,ostring2); // Concatenating the two strings, III+I=IIII
	ReplaceSubtractives(ostring1); // Replace IIII with IV
    	return ostring1;
}
