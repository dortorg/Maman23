/*
 * word.c
 *
 *  Created on: May 6, 2017
 *      Author: Dor
 */


#include "wordHandler.h"
#include <unistd.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>

FILE *wf;
int number_line = 0;
int number_words = 0;
Word* head;

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
	Word* temp = head;

	while(head != NULL)
	{
		temp = head;
		free(temp->lines_apper);
		free(temp->word);
		head = head->next;
		free(temp);
	}
	fclose(wf);
}


void insertInOrder(char *data, int line)
{
		struct word * current;
	struct word * new_node = (struct word *)malloc(sizeof(struct word));
	new_node->word = malloc(sizeof(char) * strlen(data));
	   strncpy(new_node->word, data, 20);
	   new_node->size = 1;
	   new_node->lines_apper = (int*)malloc(sizeof(int));
	   new_node->lines_apper[new_node->size - 1] = line;

		    /* Special case for the head end */
	    if (head == NULL || strcmp((head)->word, new_node->word) > 0)
	    {
	        new_node->next = head;
	        head = new_node;
	    }
	    else
	    {
	        /* Locate the node before the point of insertion */
	        current = head;
	        while (current->next!=NULL &&
	               strcmp(current->next->word, new_node->word) < 0)
	        {
	            current = current->next;
	        }
	        new_node->next = current->next;
	        current->next = new_node;
	    }
}

void printWords()
{
	int i;
	Word* temp = head;
	while(temp != NULL)
	{
		fprintf(wf, "%s ", temp->word);
		if(temp->size == 1)
		{
			fprintf(wf, "appear in line %d", temp->lines_apper[0]);
		}
		else
		{
			fprintf(wf, "appears in line ");
			for(i = 0; i < temp->size; ++i)
			{
				fprintf(wf, "%d ", temp->lines_apper[i]);
			}
		}
fprintf(wf, "\n");
		temp = temp->next;
	}
fprintf(wf, "The End\n");
}

void add(char* str)
{
	Word * position;

	if((position = exist(str)) == NULL)
	{

		number_words++;
		insertInOrder(str, number_line);
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
	word = strtok (str," ,.-\n\t()");
	add(word);
	while ((word = strtok (NULL," ,.-\n\t()")) != NULL)
    {
		 add(word);
	}
}

Word* exist(char* str)
{
	int i = 0;
	Word* temp = head;
	while(temp != NULL)
	{
		i++;
		if(strcmp(str, temp->word) == 0)
		{
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
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

