// Sean Szumlanski
// COP 3502, Spring 2017

// ========================
// SmartArray: testcase05.c
// ========================


#include <stdio.h>
#include <stdlib.h>
#include "SmartArray.h"

int main(void)
{
	SmartArray *smarty = createSmartArray(10);
	trimSmartArray(smarty);
	destroySmartArray(smarty);

	return 0;
}
