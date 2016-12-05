#ifndef __ANILAM_TREENODE__
#define __ANILAM_TREENODE__

struct TreeNode {
	struct TreeNode* left;
	struct TreeNode* right;
	char* item;
	int height;
	int freq;
};

typedef struct TreeNode TreeNode;

/**
 * CreateSingleNode
 * Allocates memory for a single node.
 */

TreeNode* createSingleNode(char* item);

/**
 * Insert
 * Inserts an item into the root as a node.
 */

TreeNode* insert(TreeNode* root, char* item);

/**
 * Delete
 * Deletes the item from the list.
 */

TreeNode* delete(TreeNode* root, char* item);

/**
 * RightRotate
 * Rotates the root right-wards
 */

TreeNode* rightRotate(TreeNode* root);

/**
 * LeftRotate
 * Rotates the root left-wards
 */

TreeNode* leftRotate(TreeNode* root);

/**
 * GetMinMode
 * Returns the last left most node.
 */

TreeNode* getMinNode(TreeNode* root, TreeNode* min);

/**
 * Search
 * Searches the tree for the item and returns it.
 */

TreeNode* search(TreeNode* root, char* item);

/**
 * SearchFreq
 * Searches and returns all nodes that are above freq.
 */

void searchFreq(TreeNode* root, int freq);

/**
 * getSize
 * Returns the size of the tree
 */

int getSize(TreeNode* root);

/**
 * Balance factor
 * Returns the balance factor of the tree
 */

int getBalanceFactor(TreeNode* root);

/**
 * getHeight
 * Returns the height of the tree
 */

int getHeight(TreeNode* root);

/**
 * FreeTree
 * Destroys the tree.
 */

void freeTree(TreeNode* root);

#endif