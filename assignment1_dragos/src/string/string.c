// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	//labul 1 de SO
	for(*destination = *source; *source != '\0'; source++, destination++) //for de la startul sursei pana la incheiere
	{
		*destination = *source;
	}
	*destination = *source;
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	size_t i = 0;
	for(i = 0; i < len; i++, ++destination, ++source)
	{
		*destination = *source;
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	//labul 1 de SO
	for( destination = destination + strlen(destination); *source != '\0'; destination++, source++ )
	{
		*destination = *source;
	}
	*destination = *source;
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	size_t i = 0;
	//am facut for de la 1 la len si am copiat sursa in destinatie  (labul 1 SO adaptat)
	for(destination = destination + strlen(destination); i < len; destination++, source++, i++)
	{
		*destination = *source;
	}
	if(len != 0)
		*destination = '\0';
	else
		return 0;
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	while(*str1 != '\0' && *str2 != '\0' && *str1 == *str2) //cat timp parcurg stringurile si sunt egale
	{
		str1++;
		str2++;
	}
	if(*str1 == '\0' && *str2 != '\0' ) //daca primul string e mai mic
	return -1;
	if(*str1 != '\0' && *str2 == '\0' ) //daca primul string e mai mare
	return 1;
	if( *str1 == '\0' && *str2 == '\0' ) //daca sunt egale
	return 0;
	else
	return *str1 - *str2; //intra pe acest caz daca ultimul caracter difera
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	//https://opensource.apple.com/source/Libc/Libc-167/gen.subproj/i386.subproj/strncmp.c.auto.html
	size_t i = 0;
	if(len == 0)
		return 0;
	while(*str1 == *str2 && i < len && ( *str1 != 0 || *str2 !=0 )) //cat timp stringurile sunt egale pana la valoarea len
	{
		if(*str1 != *str2) //daca sunt diferite
			return ( *(unsigned char *) str1 - *(unsigned char *) str2 ); //intorc diferenta
		str1++;
		str2++;
		i++;
	}
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	// https://stackoverflow.com/questions/14367727/how-does-strchr-implementation-work
	const char caracter = c;
	while(*str != caracter)//cat timp nu gasesc caracterul
	{
		if(*str == '\0')//daca ajung la final si nu gasesc caracterul
			return NULL;
		str++;
	}
	return (char *) str;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	//https://android.googlesource.com/platform/bionic/+/ics-mr0/libc/string/strrchr.c
	char *copie; //copie la aparitia caracterului
	for( copie = NULL; ; ++str )
	{
		if( *str == c )
			copie = (char *) str;
		if( *str == '\0' )
			return copie;
	}
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	//https://opensource.apple.com/source/Libc/Libc-1158.30.7/string/FreeBSD/strstr.c.auto.html
	if(*needle == '\0')
		return (char *)haystack;
	while( *haystack != '\0' )
	{
		const char *h = haystack;
		const char *n = needle;
		while(*h != '\0' && *n != '\0' && *h == *n)
		{
			h++;
			n++;
		}
		if(*n == '\0')
			return (char *) haystack;
		haystack++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	//https://github.com/brgl/busybox/blob/master/libbb/strrstr.c
	if(*needle == '\0')
		return (char *) haystack + strlen (haystack);
	const char *ultimul = NULL;
	const char *curent = strstr(haystack, needle);
	while(curent != NULL)
	{
		ultimul = curent;
		curent = strstr(ultimul + 1, needle);
	}
	return (char *) ultimul;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	//https://student.cs.uwaterloo.ca/~cs350/common/os161-src-html/doxygen/html/memcpy_8c_source.html
	size_t i = 0;
	if((uint64_t) destination % sizeof(long) == 0 && (uint64_t) source % sizeof(long) == 0 && num%sizeof(long) == 0)
	{
		const long *meminitiala = source;
		long *memfinala = destination;
		for(i = 0; i < num / sizeof(long); i++)
			memfinala[i] = meminitiala[i];
	} else {
		char *memfinala = destination;
		const char *meminitiala = source;
		for(i = 0; i < num; i++)
		{
			memfinala[i] = meminitiala[i];
		}
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	//https://student.cs.uwaterloo.ca/~cs350/common/os161-1.99-src-html/doxygen/html/memmove_8c_source.html
	size_t i;
	if((uint64_t) destination % sizeof(long) == 0 && (uint64_t) source % sizeof(long) == 0 && num % sizeof(long) == 0)
	{
		const long *meminitiala = source;
		long *memfinala = destination;
		for(i = 0; i < num / sizeof(long); i++)
			memfinala[i] = meminitiala[i];
	} else {
		const char *meminitiala = source;
		char *memfinala = destination;
		i = num;
		for(i = 0; i < num; i++)
			memfinala[i] = meminitiala[i];
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	//https://student.cs.uwaterloo.ca/~cs350/common/os161-1.99-src-html/doxygen/html/memmove_8c_source.html
	const unsigned char *str1 = ptr1;
	const unsigned char *str2 = ptr2;
	size_t i = 0;
	int d = 0;
	const unsigned char *incheiere = str1 + num;
	for( i = 0; i < num; i++ )
	{
		if ( d != 0 || str1 >= incheiere )
		break;
		d = (int) *str1++ - (int) *str2++;
	}
	return d;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	//https://git.musl-libc.org/cgit/musl/tree/src/string/memset.c
	size_t i;
	unsigned char *string = source;
	for(i = 0; i < num; i++)
	{
		*string = value;
		string++;
	}
	return source;
}
