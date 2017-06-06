/*
 * word.h
 *
 *  Created on: May 6, 2017
 *      Author: Dor
 */

#ifndef WORD_H_
#define WORD_H_
/*
 * This class responsible of handling the content of the file,
 *  and make new file with the number of line every word exist
 */

/*
 * represent one word, and the lines it appear
 * */
typedef struct word
{
	int *lines_apper;
	char *word;
	int size;
	struct word* next;
}Word;

/*
 * init the file to write and the array of words
 * */
void init(char* fileName);

/*
 * release from memory and close the file
 * */
void deinit();

/*
 * change to lowercase
 * */
char* toLower(char *str);

/*
 * the main function that handling the line
 * */
void handleLine(char* str);

/*
 * check if the word exist in the array
 * */
Word* exist(char* str);

/*
 * add word to array
 * */
void add(char* str);

/*
 * write to file the arrayof words
 * */
void printWords();

/*insert link in order*/
void insertInOrder(char *data, int line);

#endif /* WORD_H_ */

