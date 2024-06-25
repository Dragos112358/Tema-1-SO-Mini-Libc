#include <time.h>
#include<internal/syscall.h>
#include<unistd.h>
#include <internal/types.h>
#include <errno.h>
int nanosleep(const struct timespec *t1, const struct timespec *t2)
{
	//am folosit modelul de syscall de la read_write.c
	int ret = syscall(__NR_nanosleep, t1, t2);
	if(ret < 0) {
		errno = -ret;
		return ret;
	}
	return 0;
}
