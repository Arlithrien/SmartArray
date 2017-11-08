// Sean Szumlanski
// COP 3502, Spring 2017

// ========================
// SmartArray: testcase00.c
// ========================


#include <stdio.h>
#include "SmartArray.h"

int main(void)
{
	SmartArray *smarty = createSmartArray(0);
	put(smarty, "caterpillar");
	put(smarty, "beatific");
	put(smarty, "cocoon");

	printSmartArray(smarty);

	return 0;
}
