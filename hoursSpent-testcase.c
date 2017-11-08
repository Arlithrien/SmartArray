// Sean Szumlanski
// COP 3502, Spring 2017

// =================================
// SmartArray: hoursSpent-testcase.c
// =================================
// Boundary check to make sure your hoursSpent() function is implemented
// correctly.


#include <stdio.h>
#include "SmartArray.h"

int main(void)
{
	int success = 1;

	if (hoursSpent() <= 0.0 || hoursSpent() > 80.0)
		success = 0;

	printf("%s\n", success ? "Hooray!!" : "fail whale :(");

	return 0;
}
