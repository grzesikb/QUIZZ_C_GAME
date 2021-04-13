#pragma once
#pragma once
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

// ____CHEEKS IF REQUIRED ELEMENT WORKS CORRECTLY____ //
// ____IF NOT PROGRAM WILL BE CLOSED____ //
void must_init_exit(bool test, const char* description)
{
	if (test)
	{
		printf("// ____STATUS INFO____ //\n");
		printf("CHECKING: %s\n", description);
		printf("STATUS :: CORRECT\n");
		printf("// ____END OF STATUS INFO____ //\n\n");
	}
	else
	{
		printf("// ____STATUS INFO____ //\n");
		printf("CHECKING: %s\n", description);
		printf("STATUS :: FAILURE\n");
		printf("// ____END OF STATUS INFO____ //\n");
		Sleep(2000);
		exit(1);
	}
}

bool must_init_get_info(bool test, const char* description)
{
	if (test)
	{
		printf("// ____STATUS INFO____ //\n");
		printf("CHECKING: %s\n", description);
		printf("STATUS :: CORRECT\n");
		printf("// ____END OF STATUS INFO____ //\n\n");
		return true;
	}
	else
	{
		printf("// ____STATUS INFO____ //\n");
		printf("CHECKING: %s\n", description);
		printf("STATUS :: FAILURE\n");
		printf("// ____END OF STATUS INFO____ //\n\n");
		return false;
	}
}