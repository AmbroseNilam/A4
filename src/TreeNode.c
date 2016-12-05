/****************************************
 * Ambrose Nilam                0932038 *
 * CIS*2520                     A4      *
 * November 28th 2016                   *
*****************************************/

#include <stdlib.h>
#include "TreeNode.h"
#include "process.h"
#include <string.h>
#include <stdio.h>

TreeNode* createSingleNode(char* item) {
	TreeNode* toReturn = (TreeNode*) malloc(sizeof(TreeNode));
	toReturn -> left = NULL;
	toReturn -> right = NULL;
	toReturn -> item = String(item);
	toReturn -> height = 1;
	toReturn -> freq = 1;
	return toReturn;
}

int getBalanceFactor(TreeNode* root) {
	return root == NULL ? 0 : ((getHeight(root -> left)) - (getHeight(root -> right)));
}

/* Recurively decrement and delete the item from the tree. After deleteion re balance. */
TreeNode* delete(TreeNode* root, char* item) {
	if(root != NULL) {
		int compare = strcmp(item, root -> item);
		if (compare == 0) {
			root -> freq = root -> freq - 1;
			if(root -> freq == 0) {
				if(root -> left == NULL || root -> right == NULL) {
					TreeNode* toDelete = NULL;

					if(root -> left != NULL) {
						toDelete = root -> left;
					} else if (root -> right != NULL) {
						toDelete = root -> right;
					} 

					if(toDelete == NULL) {
						toDelete = root;
						root = NULL;
					} else {
						root = toDelete;
					}

					free(toDelete);
				} else {
					TreeNode* tmp = getMinNode(root -> right, NULL);
					strcpy(root -> item, tmp -> item);
					root -> right = delete(root -> right, tmp -> item);
				}
			}
		} else if (compare < 0) {
			root -> left = delete(root -> left, item);
		} else if (compare > 0) {
			root -> right = delete(root -> right, item);
		}
	}

	if(root == NULL) {
		return root;
	}

	root -> height = getHeight(root);
	int balanceFactor = getBalanceFactor(root);

	if (balanceFactor > 1) {
    	if (root -> left -> left != NULL && root -> left -> right == NULL) {
        	root = rightRotate(root);
    	} else if (root -> left -> right != NULL && root -> left -> left == NULL) {
    		root -> left = leftRotate(root -> left);
    		root = rightRotate(root);
    	} else if (root -> left -> right != NULL && root -> left -> left != NULL) {
    		//Compare height
    		int leftHeight = getHeight(root -> left -> left);
    		int rightHeight = getHeight(root -> left -> right);

    		if(leftHeight >= rightHeight) {
    			root = rightRotate(root);
    		} else if (leftHeight < rightHeight) {
    			root -> left = leftRotate(root -> left);
        		root = rightRotate(root);
    		}
    	}
	}
      else if (balanceFactor < -1) {
    	if (root -> right -> left != NULL && root -> right -> right == NULL) {
    		root -> right = rightRotate(root -> right);
        	root = leftRotate(root);
    	} else if (root -> right -> right != NULL && root -> right -> left == NULL) {
    		root = leftRotate(root);
    	} else if (root -> right -> right != NULL && root -> right -> left != NULL) {
    		//Compare height
    		int leftHeight = getHeight(root -> right -> left);
    		int rightHeight = getHeight(root -> right -> right);

    		if(leftHeight <= rightHeight) {
    			root = leftRotate(root);
    		} else if (leftHeight > rightHeight) {
    			root -> right = rightRotate(root -> right);
        		root = leftRotate(root);
    		}
    	}
    }

    root -> height = getHeight(root);
	return root;
}

/* Recurively increment or add the item to the tree. After insertion re balance. */

TreeNode* insert(TreeNode* root, char* item) {
	if (root != NULL) {
		int compare = strcmp(item, root -> item);
		//printf("Compare %s with %s = %d\n", root -> item, item, compare);
		if (compare == 0) {
			root -> freq = root -> freq + 1;
		} else if (compare < 0) {
			root -> left = insert(root -> left, item);
		} else if (compare > 0) {
			root -> right = insert(root -> right, item);
		}
	} else {
		//printf("Adding %s\n", item);
		return createSingleNode(item);
	}

	//Update height or re calculate hight.

	root -> height = getHeight(root);
	int balanceFactor = getBalanceFactor(root);

	//rintf("BF: for %s %d\n",  root -> item, balanceFactor);


	if (balanceFactor > 1) {
    	if (root -> left -> left != NULL && root -> left -> right == NULL) {
        	root = rightRotate(root);
    	} else if (root -> left -> right != NULL && root -> left -> left == NULL) {
    		root -> left = leftRotate(root -> left);
    		root = rightRotate(root);
    	} else if (root -> left -> right != NULL && root -> left -> left != NULL) {
    		//Compare height
    		int leftHeight = getHeight(root -> left -> left);
    		int rightHeight = getHeight(root -> left -> right);

    		if(leftHeight >= rightHeight) {
    			root = rightRotate(root);
    		} else if (leftHeight < rightHeight) {
    			root -> left = leftRotate(root -> left);
        		root = rightRotate(root);
    		}
    	}
	}
 
    // Right Right Case
     else if (balanceFactor < -1) {
    	if (root -> right -> left != NULL && root -> right -> right == NULL) {
    		root -> right = rightRotate(root -> right);
        	root = leftRotate(root);
    	} else if (root -> right -> right != NULL && root -> right -> left == NULL) {
    		root = leftRotate(root);
    	} else if (root -> right -> right != NULL && root -> right -> left != NULL) {
    		//Compare height
    		int leftHeight = getHeight(root -> right -> left);
    		int rightHeight = getHeight(root -> right -> right);

    		if(leftHeight <= rightHeight) {
    			root = leftRotate(root);
    		} else if (leftHeight > rightHeight) {
    			root -> right = rightRotate(root -> right);
        		root = leftRotate(root);
    		}
    	}
    }

	// update balance factor 
    // update height

    root -> height = getHeight(root);

    return root;
}


int getHeight(TreeNode* root) { // maximum of left and right + 1
	return root == NULL ? 0 : getMax(getHeight(root -> left), getHeight(root -> right)) + 1;
}

int getSize(TreeNode* root) {  
    return root == NULL ? 0 : (getSize(root->left) + getSize(root->right) + 1);  
}

TreeNode* rightRotate(TreeNode* root) {

	TreeNode* tmp = root -> left;
	root -> left = tmp -> right;
	tmp -> right = root;

	root -> height = getHeight(root);
	tmp -> height = getHeight(tmp);
	return tmp;
}

TreeNode* getMinNode(TreeNode* root, TreeNode* min)
{
	return root == NULL ? min : getMinNode(root -> left, root);
}

TreeNode* search(TreeNode* root, char* item) { // compare are recursively return.
	if(root == NULL) {
		return NULL;
	}

	int compare = strcmp(item, root -> item);

	if (compare < 0) {
		return search(root -> left, item);
	} else if (compare > 0) {
		return search(root -> right, item);
	} else {
		return root;
	}
}

void searchFreq(TreeNode* root, int freq) { // Print based on condition recursively until null.
	if(root == NULL)
		return;

	searchFreq(root -> right, freq);

	if(root -> freq > freq) {
		printf("key: %s, frequencey: %d\n", root -> item, root -> freq);
	}
	
	searchFreq(root -> left, freq);
}

void freeTree(TreeNode* root)
{
    if (root == NULL)
        return;

    freeTree(root -> left);
    freeTree(root -> right);
    free(root);
}

TreeNode* leftRotate(TreeNode* root) {

	TreeNode* tmp = root -> right;
	root -> right = tmp -> left;
	tmp -> left = root;

	root -> height = getHeight(root);
	tmp -> height = getHeight(tmp);
	return tmp;
}






