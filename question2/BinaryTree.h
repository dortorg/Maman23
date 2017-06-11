/*
 * BinaryTree.h
 *
 *  Created on: Jun 10, 2017
 *      Author: Dor
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <stdio.h>

typedef struct Node
{
	int *lines_apper;
	char *word;
	unsigned size;
	struct Node *left;
    struct Node *right;
}Node;

/*
 * destroy the tree and deallocate the memory
 */
void destroy_tree(struct Node *leaf);

/*
 * insert the data to the binary search tree recursibly
 */
void insert(char* key, int line,  Node **leaf);

/*
 * search Node in the binary search tree
 */
struct Node *search(char* key, struct Node *leaf);

/*
 * print to file the content of the tree inorder
 */
void inorder(Node *temp, FILE *rf);


#endif /* BINARYTREE_H_ */
