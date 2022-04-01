#include "hash.h"
#include <stdint.h>

uint64_t	hash_gen_fnv1a(char *s)
{
	static const uint64_t	offset = 14695981039346656037UL;
	static const uint64_t	prime = 1099511628211UL;
	uint64_t				hash;
	uint8_t					byte;

	hash = offset;
	while (*s)
	{
		byte = *s;
		hash ^= byte;
		hash *= prime;
		s++;
	}
	return (hash);
}
