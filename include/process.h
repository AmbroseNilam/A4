#ifndef __ANILAM_PROCESS__
#define __ANILAM_PROCESS__


char* String(char*);

char* infixToPostfix(char*);

int precedance(char);

int getMax(int a, int b);

int isOperator(char);

/**
 * subString
 * Function will create a new Sring given an input string. The new String will contain all characters starting from the specified index.
 * IN: String output - What the function with write data to. String input - The function will use this data. int Startindex - The starting index. int endIndex - Ending index. 
 * Out: NONE
 * POST: The function will exit if un-wanted information is accessed.
 */

char* subString(char*, int, int);

/**
 * append
 * Concatinates two strings together.
 * String input: Original String. String toAdd: The string to append.
 * Out: New String with both Strings concatinated
 * POST: Will return empty string if invalid input.
 */

char* append(char* input, char* toAdd);

/**
 * split
 * Function will split a string from the delimeter and will return an array of all strings.
 * String input - The String to split, Char delim - The delimeter to split from
 * Out: A new array of Strings that were split.
 * POST: The function will exit if un-wanted information is accessed.
 */
char** split(char*, char);

/**
 * indexOf
 * Function will return the first occurance of the index of a given character in a sequence of characters.
 * IN: String input - The function will use this data. Char key - The key to search for.
 * Out: The function will return the index once it is found.
 * POST: The function will return -1 if nothing is found.
 */

int indexOf(char[], char, int);

/**
 * findMax
 * Function will return the maximum value given an array of integers.
 * IN: integer array - The predefined array of integers. int - Length of array.
 * Out: Return the maximum value inside given array.
 * POST: The function will return the first element no other greater elements are found.
 */
int findMax(int[], int);

/**
 * getNumChar
 * Function will return the number of occurances of a single character an a string literal.
 * IN: String Literal and char to search for.
 * Out: Return the amount of occurances of that character.
 * POST: The function will return -1 if not found.
 */
int getNumChar(char*, char);

/**
 * beforeAndAfter
 * Function will return the two integers between a character deilimitter.
 * IN: Character array - The input String, Char - Delimmiter that will be used to split.
 * Out: Return array containing two integer values.
 * POST: The function will return the array containing two values of negative 1.
 */
int* beforeAndAfter(char[], char);

/**
 * getAllDigits
 * Function will return all found digits in a string literal.
 * IN: Char array - The String literal.
 * Out: Return the integer value inside the string. 
 * POST: Only accounts for a single integer value - This is specfically used for doors - (ie. de4 will return 4).
 */
int getAllDigits(char[]);

/**
 * emptyString
 * Functon will empty the string by putting null terminators.
 * IN: String output - What the function with write data to. String input - The function will use this data. int index - The starting index.
 * Out: NONE
 * POST: NONE
 */
void emptyString(char[]);

int getNumChar(char*, char);
#endif