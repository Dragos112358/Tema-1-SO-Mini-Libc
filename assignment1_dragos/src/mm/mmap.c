// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>
#include <string.h>
//#include <stdint.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */
	//https://linux.die.net/man/2/mmap
	//https://git.musl-libc.org/cgit/musl/tree/src/mman/mmap.c?h=v1.1.15
	//MAP_ANONYMOUS are cod de flag 32
	if(fd > 0)
	{
		errno = EBADF;
		return MAP_FAILED;
	}
	if(flags == 32)
	{
		errno = EINVAL;
		return MAP_FAILED;
	}
	void *ret = (void *)syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
	if(ret == MAP_FAILED)
	{
		errno = 1;
		return MAP_FAILED;
	}
	return (void *) ret;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	//https://sites.uclouvain.be/SystInfo/manpages/man2/mremap.2.html
	//facut pe modelul read_write.c
	void *ret = (void *)syscall(__NR_mremap, old_address, old_size, new_size, flags);
	if(ret == MAP_FAILED){
		errno = 1;
		return MAP_FAILED;
	}
	return ret;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	//https://man7.org/linux/man-pages/man3/munmap.3p.html
	int ret = syscall(__NR_munmap, addr, length);
	if(ret < 0)
	{
		errno = EINVAL;
		return  -1;
	}
	return 0;
}
