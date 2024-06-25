// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>
#include <unistd.h>
int fstat(int fd, struct stat *st)
{
	/* TODO: Implement fstat(). */
	//facut pe modelul read_write.c
	//https://man7.org/linux/man-pages/man3/fstat.3p.html
	int ret = syscall(__NR_fstat, fd, st);
	if(ret < 0)
	{
		errno = -ret;
		return -1;
	}
	return 0;
}
