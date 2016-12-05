all: main

main: src/avltree.c src/process.c src/TreeNode.c include/TreeNode.h include/process.h
	gcc -Wall -std=c99 src/process.c src/TreeNode.c src/avltree.c -Iinclude -o avltree