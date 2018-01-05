#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef MAXSIZE
#define MAXSIZE 100
#endif

typedef int elementType;

typedef struct
{
	int element[MAXSIZE];
	int length;
} sqList;
