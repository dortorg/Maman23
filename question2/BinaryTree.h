/*
 * BinaryTree.h
 *
 *  Created on: Jun 10, 2017
 *      Author: Dor
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_


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

void inorder(node *temp);


#endif /* BINARYTREE_H_ */
