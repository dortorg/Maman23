/*
 * utils.c
 *
 *  Created on: May 6, 2017
 *      Author: Dor
 */

#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>


void validateInput(int argc, char* argv[])
{
	if(argc > 2)
	{
		fprintf(stderr, "Too much arguments\n");
		exit(0);
	}
	if(argc < 2)
	{
		fprintf(stderr, "No arguments\n");
		exit(0);
	}
	rf = fopen(argv[1],"r");
	if(rf == NULL)
	{
		fprintf(stderr, "Error opening file: %s\n", strerror(errno));
		exit(0);
	}
}

unsigned getdelim(char **buf, size_t *bufsiz, int delimiter, FILE *fp)
{
	char *ptr, *eptr;


	if (*buf == NULL || *bufsiz == 0) {
		*bufsiz = BUFSIZ;
		if ((*buf = malloc(*bufsiz)) == NULL)
			return -1;
	}

	for (ptr = *buf, eptr = *buf + *bufsiz;;) {
		int c = fgetc(fp);
		if (c == -1) {
			if (feof(fp))
				return ptr == *buf ? -1 : ptr - *buf;
			else
				return -1;
		}
		*ptr++ = c;
		if (c == delimiter) {
			*ptr = '\0';
			return ptr - *buf;
		}
		if (ptr + 2 >= eptr) {
			char *nbuf;
			unsigned nbufsiz = *bufsiz * 2;
			unsigned d = ptr - *buf;
			if ((nbuf = realloc(*buf, nbufsiz)) == NULL)
				return -1;
			*buf = nbuf;
			*bufsiz = nbufsiz;
			eptr = nbuf + nbufsiz;
			ptr = nbuf + d;
		}
	}
	return *bufsiz;
}

unsigned getLine(char **buf, size_t *bufsiz, FILE *fp)
{
	return getdelim(buf, bufsiz, '\n', fp);
}


