// Sean Szumlanski
// COP 3502, Spring 2017

// ========================
// SmartArray: testcase08.c
// ========================


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SmartArray.h"

int main(void)
{
	int i; char buffer[32], *ephemeral_string = NULL;

	SmartArray *smarty = createSmartArray(10);

	trimSmartArray(smarty);

	for (i = 0; i < 1000; i++)
	{
		sprintf(buffer, "ephemeral string #%03d", i);

		ephemeral_string = malloc(sizeof(char) * (strlen(buffer) + 1));

		strcpy(ephemeral_string, buffer);

		put(smarty, buffer);

		free(ephemeral_string);
	}

	printSmartArray(smarty);

	return 0;
}
