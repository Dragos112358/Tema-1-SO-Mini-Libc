#ifndef __TIME_H__
#define __TIME_H__
#ifdef __cplusplus
extern "C" {
#endif
#include<internal/types.h>
struct timespec {
	unsigned int tv_sec;
	long  tv_nsec;
};
unsigned int sleep(unsigned int sec);
int nanosleep(const struct timespec *t1, const struct timespec *t2);

#ifdef __cplusplus
}
#endif
#endif
