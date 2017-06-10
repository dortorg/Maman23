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


void destroy_tree( node *leaf)
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

void insert(char* key, int line,  node **leaf)
{
    if( *leaf == 0 )
    {
        (*leaf) = (struct node*) malloc( sizeof( struct node ) );
        (*leaf)->word = (char*)malloc(sizeof(char*) * strlen(key));
        strcpy((*leaf)->word, key);
        (*leaf)->size = 1;
        (*leaf)->lines_apper = (int*)malloc(sizeof(int));
        *(*leaf)->lines_apper = line;
        /* initialize the children to null */
        (*leaf)->left = 0;
        (*leaf)->right = 0;
    }
    else if(strcmp(key, (*leaf)->word) > 0 )
    {
        insert( key, line,&(*leaf)->left );
    }
    else if(strcmp(key, (*leaf)->word) < 0 )
    {
        insert( key, line,&(*leaf)->right );
    }
}

struct node *search(char* key, struct node *leaf)
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
void inorder(node *temp, FILE *rf) {
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

