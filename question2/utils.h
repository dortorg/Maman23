/*
 * utils.h
 *
 *  Created on: May 6, 2017
 *      Author: Dor
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>

/*
 * helped class with system function
 * */

/*
 * user file, the file i get from the user and read from
 * */
FILE *rf;

/*
 * validate the user input
 * */
void validateInput(int argc, char* argv[]);

/*
 * read line from file
 * */
unsigned getLine(char **buf, size_t *bufsiz, FILE *fp);

/*
 * getLine use this function
 * */

static unsigned getDelim(char **buf, size_t *bufsiz, int delimiter, FILE *fp);

#endif /* UTILS_H_ */

