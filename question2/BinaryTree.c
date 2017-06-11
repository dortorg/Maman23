/*
 * BinaryTree.c
 *
 *  Created on: Jun 10, 2017
 *      Author: Dor
 */

#include "BinaryTree.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>


void destroy_tree( Node *leaf)
{
  if( leaf != 0 )
  {
      destroy_tree(leaf->left);
      destroy_tree(leaf->right);
      free(leaf->word);
      free(leaf->lines_apper);
      free( leaf );
  }
}

void insert(char* key, int line,  Node **leaf)
{
    int number, number2;


		if( *leaf == 0 )
		{
			(*leaf) = (struct Node*) malloc( sizeof( struct Node ) );
			(*leaf)->word = (char*)malloc(sizeof(char*) * strlen(key));
			strcpy((*leaf)->word, key);
			(*leaf)->size = 1;
			(*leaf)->lines_apper = (int*)malloc(sizeof(int));
			*(*leaf)->lines_apper = line;
			/* initialize the children to null */
			(*leaf)->left = 0;
			(*leaf)->right = 0;
		}
		else if(sscanf(key, "%d", &number) != 0 && sscanf((*leaf)->word, "%d", &number2)!= 0 )
		{
			if(number < number2 )
			{
				insert( key, line,&(*leaf)->left );
			}
			else if(number > number2)
			{
				insert( key, line,&(*leaf)->right );
			}
		}
		else if(strcmp(key, (*leaf)->word) < 0 )
		{
			insert( key, line,&(*leaf)->left );
		}
		else if(strcmp(key, (*leaf)->word) > 0 )
		{
			insert( key, line,&(*leaf)->right );
		}
}

struct Node *search(char* key, struct Node *leaf)
{
  if( leaf != 0 )
  {
      if(strcmp(key, leaf->word) == 0)
      {
          return leaf;
      }
      else if(strcmp(key, leaf->word) < 0)
      {
          return search(key, leaf->left);
      }
      else
      {
          return search(key, leaf->right);
      }
  }
  else return 0;
}

/*
 This function displays the tree in inorder fashion
 */
void inorder(Node *temp, FILE *rf) {
	int i;
   if (temp != NULL) {
      inorder(temp->left, rf);
	  fprintf(rf, "%s ", temp->word);
		if(temp->size == 1)
		{
			fprintf(rf, "appear in line %d", temp->lines_apper[0]);
		}
		else
		{
			fprintf(rf, "appears in line ");
			for(i = 0; i < temp->size; ++i)
			{
				fprintf(rf, "%d ", temp->lines_apper[i]);
			}
		}
	  fprintf(rf, "\n");
      inorder(temp->right, rf);
   }
}

