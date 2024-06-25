// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <stdio.h>
int close(int fd)
{
	/* TODO: Implement close(). */
	//implementare pe modelul read_write.c
	int ret = syscall(__NR_close, fd);
	if(ret < 0) {
		errno = -ret;
		return -1;
	}
	return ret;
}
