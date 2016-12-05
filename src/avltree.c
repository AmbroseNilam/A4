/****************************************
 * Ambrose Nilam                0932038 *
 * CIS*2520                     A4      *
 * November 28th 2016                   *
*****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "process.h"
#include "TreeNode.h"


void userInput(char*, int);

int main() {
    printf("\n%s\n", "Name: \"Ambrose Nilam\"\nStudent ID: \"0932038\"\nWelcome to AVL Tree!\n");
    
    char* options[] = {"Initialization", "Find", "Insert", "Remove", "Check Height and Size", "Find All (above a given frequency)", "Exit"};
    int length = sizeof(options) / sizeof(char*);
    
    int selection = -1;
    
    TreeNode* AVL = NULL;  // AVL Tree

    do {
        char* input = (char*) malloc(sizeof(char) + 1);
        
        for(int i = 0; i < length; i++) {
            printf("%d. %s\n", (i + 1), options[i]);
        }
        
        printf("%s ", "avl/>");
        
        userInput(input, sizeof(input)); // Get user input.
        selection = atoi(input); // parse to int
        
        char* fileName = (char*) malloc(sizeof(char) * 255);
        char* searchKey = (char*) malloc(sizeof(char) * 255);
        char* insertKey = (char*) malloc(sizeof(char) * 255);
        char* removeKey = (char*) malloc(sizeof(char) * 255);
        char* freq = (char*) malloc(sizeof(char) * 255); // malloc for user input.

        switch(selection) { // For each case user can select.
            case 1:
                printf("%s ", "Enter the file name:");
                userInput(fileName, sizeof(fileName));
                FILE* file = fopen(fileName, "r");
                char line[255];
                if (file != NULL) {
                    while(fscanf(file, "%s", line) == 1) // Parse each String inside line.
                    {
                        char* val = String(line);
                        AVL = insert(AVL, val); // insert into tree
                        free(val);
                    }
                }
                fclose(file);
                break;
            case 2:
                printf("%s ", "find key:");
                userInput(searchKey, sizeof(searchKey));
                TreeNode* searchedKeyNode = search(AVL, searchKey);
                if(searchedKeyNode != NULL) {
                    printf("key: %s, frequency: %d\n", searchedKeyNode -> item, searchedKeyNode -> freq);
                } else {
                    printf("%s\n", "no_such_key");
                }
                break;
            case 3:
                printf("%s ", "insert key:");
                userInput(insertKey, sizeof(insertKey));
                AVL = insert(AVL, insertKey);

                TreeNode* searchedInsertNode = search(AVL, insertKey);
                if(searchedInsertNode != NULL) {
                    printf("key: %s, frequency: %d\n", searchedInsertNode -> item, searchedInsertNode -> freq);
                }

                break;
            case 4:
                printf("%s ", "remove key:");
                userInput(removeKey, sizeof(removeKey));
                TreeNode* searchedRemoveNode = search(AVL, removeKey);

                if(searchedRemoveNode != NULL) {
                    AVL = delete(AVL, removeKey);
                    TreeNode* deletedNode = search(AVL, removeKey);

                    if(deletedNode != NULL) {
                        printf("key: %s, frequency: %d\n", deletedNode -> item, deletedNode -> freq);
                    }
                } else {
                    printf("%s\n", "no_such_key");
                }
                break;
            case 5:
                printf("height: %d, size: %d\n", getHeight(AVL), getSize(AVL));       
     
                break;
            case 6:
                printf("%s ", "frequency:");
                userInput(freq, sizeof(freq));
                searchFreq(AVL, atoi(freq));
                break;
            case 7:
                freeTree(AVL);
                break;
            default:
                printf("%s\n", "Invalid option please enter numeric value (1 - 7)!");
                break;
        }
        
        printf("%s\n", "");
    } while(selection != 7);
    return 0;
}

void userInput(char* input, int length)
{
    fgets(input,length,stdin);
    
    for(int i = 0; i <= length; i++)
    {
        if(input[i] == '\n')
        {
            input[i] = '\0';
            return;
        }
    }
}
