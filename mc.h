#include <stdlib.h>
#include <stdio.h>

FILE * file_;
errno_t err_;

enum errors_type
{
	ERROR_FILE_NO_EXISTS = 10,
	SEMICOLON_NO_EXISTS = 20,
	FUNCTION_NO_EXISTS = 30
};