******************************************
Ambrose Nilam        		0932038
CIS*2520	               	A4
November 28th 2016
******************************************

***********
Compilation
***********

The command that was used to compile the program was gcc, the compile line being gcc -Wall -std=c99.
"gcc -Wall -std=c99 src/process.c src/TreeNode.c src/avltree.c -Iinclude -o avltree"

To compile the program using gcc and create an executable simply type 'make'.

******************
USAGE
******************
- To run the program we have to first compile using the command above 'make' and create an executable. Once the executable is created, we must execute it using './avltree'
- The program will start and give user options

***********************
Testing / Execution
Usage / Output
***********************

1. Program will parse data file and insert into nodes. (Option 1 -> file_name = 'data')
2. All functions tested using the data file provided.

3. Insert function works without data file.
4. All functions can be tested by manually create the tree.

******************
Known Errors/Constraints
******************
- The program may fail if the memory is not allocated properly or system does not have enough memory.
- Deletion may cause a segmentation fault at sometimes when the node is being completely deleted.
- Program works on Apple Macbook Pro laptop without crash. Did not validate on servers thoroughly.
- Frequency search may fluctuate results.
- Height may be off by 1 or 2 values depending on the inital value.
