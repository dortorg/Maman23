/*
 * word.c
 *
 *  Created on: May 6, 2017
 *      Author: Dor
 */


#include "wordHandler.h"
#include "BinaryTree.h"
#include <unistd.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>

FILE *wf;
int number_line = 0;
int number_words = 0;
node* head;

void init(char* fileName)
{
	strcat(fileName, ".index");
	wf = fopen(fileName, "w+");
	if (wf == NULL)
	{
		fprintf(stderr, "Error opening file!\n");
	    exit(1);
	}
}

void deinit()
{
	destroy_tree(head);
	fclose(wf);
}

void add(char* str)
{
	node * position;
	position = search(str, head);
	if(position == NULL)
	{

		number_words++;
		insert(str, number_line, &head);
	}
	else
    {
		if(position->lines_apper[position->size - 1] != number_line)
		{
			position->size++;
			position->lines_apper = realloc(position->lines_apper, sizeof(int) * position->size );
			position->lines_apper[position->size - 1] = number_line;
		}
	}
}

void handleLine(char* str)
{
	char* word;
	number_line++;
	str = toLower(str);
	word = strtok (str," ,.-\n\t()!@#$%^&*");
	add(word);
	while ((word = strtok (NULL," ,.-\n\t()!@#$%^&*")) != NULL)
    {
		 add(word);
	}
}

char* toLower(char *str)
{
	int i;
	for(i = 0; i < strlen(str); ++i)
	{
		str[i] = (tolower(str[i]));
	}
	return str;
}

void printWords()
{
	inorder(head, wf);
}
