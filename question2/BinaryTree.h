/*
 * BinaryTree.h
 *
 *  Created on: Jun 10, 2017
 *      Author: Dor
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <stdio.h>

typedef struct node
{
	int *lines_apper;
	char *word;
	int size;
	struct node *left;
    struct node *right;
}node;


void destroy_tree(struct node *leaf);

void insert(char* key, int line,  node **leaf);

struct node *search(char* key, struct node *leaf);

void inorder(node *temp, FILE *rf);


#endif /* BINARYTREE_H_ */
