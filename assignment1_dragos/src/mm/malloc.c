#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	//https://man7.org/linux/man-pages/man3/malloc.3.html
	void *ret = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if(ret == MAP_FAILED)
		return NULL;
	if(mem_list_head.next == NULL)
		mem_list_init();
	mem_list_head.len = size;
	mem_list_add(ret, size);
	return ret;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	//syscall facut pe modelul malloc
	//realoc memoria si o setez pe 0
	void *ret = mmap(NULL, size*nmemb, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if(ret == MAP_FAILED) {
		return NULL;
	}
	void *nou = malloc(nmemb * size);
	mem_list_head.len = nmemb * size;
	memset(nou, 0, nmemb * size);
	return nou;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if(ptr == NULL)
		return;
	struct  mem_list * mem = mem_list_find(ptr);
	if(mem == MAP_FAILED)
		return;
	int ret = munmap(mem->start, mem->len);
	if(ret == -1)
		return;
	mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	//facut pe modelul calloc, dar nu initializez memoria cu 0
	void *ret = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        if (ret == MAP_FAILED) {
                return NULL;
	}
	void *nou = malloc(size);
	mem_list_head.len = size;
	if(ptr != NULL) {
		memcpy(nou, ret, size);
	}
	return nou;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	//facut fix ca realloc (la memcpy copiez memorie de dimensiunea nmemb*size)
	void *ret = mmap(NULL, size * nmemb, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        if (ret == MAP_FAILED) {
                return NULL;
	}
        void *nou = malloc(nmemb * size);
	mem_list_head.len = nmemb*size;
	if(ptr != NULL) {
        	memcpy(nou, ret, nmemb * size);
	}
        return nou;
}


