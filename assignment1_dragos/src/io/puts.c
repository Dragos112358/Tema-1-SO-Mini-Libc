#include <string.h>
#include <stdio.h>
#include <unistd.h>
int puts(const char *str)
{
	//https://www.tutorialspoint.com/c_standard_library/c_function_puts.htm
	int ret = 0;
	ret = strlen(str);
	ssize_t biti = write(1, str, ret);
	if(biti < 0) {
	return -1;
	}
	write(1, "\n", 1);
	ret++;
	return ret;
}
