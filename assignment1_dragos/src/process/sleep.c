#include <time.h>
#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
//#include<internal/mman.h>
unsigned int sleep(unsigned int sec) {
	//https://man7.org/linux/man-pages/man3/sleep.3.html
	//https://git.musl-libc.org/cgit/musl/tree/src/unistd/sleep.c
	struct timespec req, rem;
	req.tv_sec = sec;
	req.tv_nsec = 0;
	while(nanosleep(&req, &rem) == -1) {
		if(errno == EINTR) {
			req = rem;
		} else{
			return rem.tv_sec;
		}
	}
	return 0;
}
