/****************************************
 * Ambrose Nilam                0932038 *
 * CIS*2520                     A4      *
 * November 28th 2016                   *
*****************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "process.h"
#include "TreeNode.h"



int precedance(char c) {
	switch(c) {
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
	}
	return -1;
}

int isOperator(char c) {
	switch(c) {
		case '+':
		case '-':
		case '*':
		case '/':
			return 1;
	}
	return 0;
}

char* String(char* input) {
	char* toReturn = NULL;
	int length = strlen(input);

	toReturn = malloc(sizeof(char) * length + 1);

	int stringCount = 0;

	for(int i = 0; i < length; i++) {
		if(input[i] == '\n')
			continue;

		toReturn[i] = input[i];
		stringCount ++;
	}

	toReturn[stringCount] = '\0';


	return toReturn;
}

char* subString(char* input, int startIndex, int endIndex)
{
	if (startIndex < 0 || startIndex >= strlen(input) || input == NULL)
	{
		char* toReturn = malloc(sizeof(char) * 2);
		toReturn[0] = 0;
		toReturn[1] = '\0';
		return toReturn;
	}

	int stringLength = startIndex + endIndex;
	char* toReturn = malloc(sizeof(char) * stringLength + 1);
	int stringCount = 0;

	for (int i = startIndex; i < endIndex; i++)
	{
		toReturn[stringCount] = input[i];
		stringCount++;
	}
	
	toReturn[stringCount] = '\0';
	return toReturn;
}

int getMax(int a, int b) {
	return (a > b) ? a : b;

}


int getDistinctLength(char* input) {
	int length = strlen(input);
	char* toWork = malloc(sizeof(char) * length);
	int toReturn = 0;
	for(int i = 0; i < length; i++) {
		toWork[i] = input[i];
	}

	for(int i = 0; i < length; i++) {
		for(int j = 0; j < length; j++) {
			if(i != j) {
				if(toWork[i] == toWork[j]) {
					toWork[i] = '.';
				}
			}
		}
	}

	for(int i = 0; i < length; i++) {
		if(toWork[i] != '.') {
			toReturn ++;
		}
	}
	
	return toReturn;
}

int contains(char** array, char* check, int size) {
	for(int i = 0; i < size; i++) {
		if(strcmp(array[i], check) == 0) {
			return 1;
		}
	}
	return 0;
}

char* scrambleString(char* input) {
	char* toReturn = NULL;
	int stringLength = strlen(input);
	toReturn = malloc(sizeof(char) * stringLength);

	for(int i = 0; i < stringLength; i++) {
		toReturn[i] = input[i];
	}

	for(int i = 0; i < 25; i++) {
		int rndNum = (int) (rand() % stringLength);
		int rndNum2 = (int) (rand() % stringLength);
		while(rndNum == rndNum2) {
			rndNum2 = (int) (rand() % stringLength);
		}

		char save = toReturn[rndNum];
		toReturn[rndNum] = toReturn[rndNum2];
		toReturn[rndNum2] = save;
	}

	return toReturn;
}

char* trim(char* input)
{
	char* toReturn = NULL;
	int numSpaces = getNumChar(input, ' ');
	int numNewLines = getNumChar(input, '\n');
	int newLength = strlen(input) - numSpaces - numNewLines + 1;
	toReturn = malloc(sizeof(char) * (newLength));

	int counter = 0;

	for(int i = 0; i < strlen(input); i++)
	{
		if(input[i] != '\n' && input[i] != ' ')
		{
			toReturn[counter] = input[i];
			counter++;
		}
	}

	toReturn[counter] = '\0';
	return toReturn;
}

char* append(char* input, char* toAdd)
{
	char* toReturn = NULL;
	int newLength = strlen(input) + strlen(toAdd) + 1;
	toReturn = malloc(sizeof(char) * (newLength));

	int counter = 0;

	for(int i = 0; i < strlen(input); i++)
	{
		toReturn[counter] = input[i];
		counter++;
	}

	for(int i = 0; i < strlen(toAdd); i++)
	{
		toReturn[counter] = toAdd[i];
		counter++;
	}

	toReturn[counter] = '\0';
	return toReturn;
}


char** split(char* input, char delim)
{
	int size = getNumChar(input, delim) + 1;

	if(size == 0) {
		char** toReturn = (char**) malloc(sizeof(char*));
		toReturn[0] = String(input);
		return toReturn;
	}

	char** toReturn = NULL;

	toReturn = (char**) malloc(sizeof(char*) * 65555);

	for(int i = 0; i < size; i++)
	{
		toReturn[i] = malloc(sizeof(char) * 50 + 1);
	}

	int stringCounter = 0;
	int currentLength = 0;

	for(int i = 0; i < strlen(input); i++)
	{
		if(input[i] == delim)
		{
			toReturn[stringCounter][currentLength] = '\0';
			if(strlen(toReturn[stringCounter]) != 0) {
				stringCounter++;
			}
			currentLength = 0;
			i++;
		}

		if(input[i] != '\n')
		{
			toReturn[stringCounter][currentLength] = input[i];
			currentLength ++;
		}
	}

	toReturn[stringCounter + 1] = NULL;

	return toReturn;
}

int indexOf(char input[], char key, int occurance) 
{
	int i;
	int occuranceCounter;
	int toReturn;
	i = 0;
	occuranceCounter = 0;
	toReturn = 0;
	if(key == '\n') {
		occurance = 1;
	}
	for(i = 0; i < strlen(input); i++) 
	{
		if(input[i] == key) 
		{
			toReturn = i;
			occuranceCounter ++;
			if(occuranceCounter == occurance)
			{
				return toReturn;
			}
		}

	}
	return -1;
}

int findMax(int array[], int totalElements)
{
	int currentMax = array[0];
	for(int i = 0; i < totalElements; i++)
	{
		if(array[i] > currentMax)
		{
			currentMax = array[i];
		}
	}
	return currentMax;
}

int* beforeAndAfter(char input[], char delim) 
{

	char* values[2];
	int* toReturn;

	values[0] = (char*) malloc(sizeof(char) * 3);
	values[1] = (char*) malloc(sizeof(char) * 3);
	toReturn = (int*) malloc(sizeof(int) * 2);

	toReturn[0] = -1;
	toReturn[1] = -1;
	
	if(indexOf(input, delim, 1) == -1)
	{
		return toReturn;
	}
	
	int valueCounter = 0;
	int digitCounter = 0;

	for(int i = 0; i < strlen(input); i++)
	{
		if(input[i] == delim)
		{
			valueCounter++;
			digitCounter = 0;
		}

		if(isdigit((int) input[i]))
		{
			values[valueCounter][digitCounter] = input[i];
			digitCounter++;
		}

	}

	toReturn[0] = atoi(values[0]);
	toReturn[1] = atoi(values[1]);
	free(values[0]);
	free(values[1]);
	return toReturn;
 }

int getAllDigits(char input[])
{
	int check = -1;
	int toReturn;
	char* tempValues;
	tempValues = (char*) malloc(sizeof(char) * 3);
	int counter = 0;
	for (int i = 0; i < strlen(input); i++)
	{
		if(isdigit((int) input[i]))
		{
			tempValues[counter] = input[i];
			counter++;
			check = 1;
		}
	}
	toReturn = atoi(tempValues);
	free(tempValues);
	return check == -1 ? check : toReturn;
}

void emptyString(char input[]) 
{
	memset(input,0,strlen(input));
}

int getNumChar(char* input, char c)
{
	int toReturn = 0;
	for(int i = 0; i < strlen(input); i++)
	{
		if(input[i] == c)
		{
			toReturn++;
		}
	}
	return toReturn == 0 ? -1 : toReturn;
}



