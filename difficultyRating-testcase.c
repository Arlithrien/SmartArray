// Sean Szumlanski
// COP 3502, Spring 2017

// =======================================
// SmartArray: difficultyRating-testcase.c
// =======================================
// Boundary check to make sure your difficultyRating() function is implemented
// correctly.


#include <stdio.h>
#include "SmartArray.h"

int main(void)
{
	int success = 1;

	if (difficultyRating() < 1.0 || difficultyRating() > 5.0)
		success = 0;

	printf("%s\n", success ? "Hooray!!" : "fail whale :(");

	return 0;
}
