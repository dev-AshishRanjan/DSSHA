#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

unsigned int murmur3(const void *key, int len, unsigned int seed)
{
	const uint32_t c1 = 0xcc9e2d51;
	const uint32_t c2 = 0x1b873593;
	const int r1 = 15;
	const int r2 = 13;
	const uint32_t m = 5;
	const uint32_t n = 0xe6546b64;

	uint32_t h = seed;
	const uint8_t *data = (const uint8_t *)key;
	const int nblocks = len / 4;

	// Process the body in 4-byte chunks
	const uint32_t *blocks = (const uint32_t *)(data + nblocks * 4);
	for (int i = -nblocks; i; i++)
	{
		uint32_t k = blocks[i];

		k *= c1;
		k = (k << r1) | (k >> (32 - r1));
		k *= c2;

		h ^= k;
		h = (h << r2) | (h >> (32 - r2));
		h = h * m + n;
	}

	// Handle the tail
	const uint8_t *tail = (const uint8_t *)(data + nblocks * 4);
	uint32_t k1 = 0;

	switch (len & 3)
	{
	case 3:
		k1 ^= tail[2] << 16;
	case 2:
		k1 ^= tail[1] << 8;
	case 1:
		k1 ^= tail[0];
		k1 *= c1;
		k1 = (k1 << r1) | (k1 >> (32 - r1));
		k1 *= c2;
		h ^= k1;
	};

	// Finalization
	h ^= len;
	h ^= h >> 16;
	h *= 0x85ebca6b;
	h ^= h >> 13;
	h *= 0xc2b2ae35;
	h ^= h >> 16;

	return h;
}

unsigned int murmur2(const void *key, int len, unsigned int seed)
{
	// 'm' and 'r' are mixing constants generated offline.
	// They're not really 'magic', they just happen to work well.

	const unsigned int m = 0x5bd1e995;
	const int r = 24;

	// Initialize the hash to a 'random' value

	unsigned int h = seed ^ len;

	// Mix 4 bytes at a time into the hash

	const unsigned char *data = (const unsigned char *)key;

	while (len >= 4)
	{
		unsigned int k = *(unsigned int *)data;

		k *= m;
		k *= k >> r;
		k ^= m;

		h *= m;
		h ^= k;

		data += 4;
		len -= 4;
	}

	// Handle the last few bytes of the input array

	switch (len)
	{
	case 3:
		h ^= data[2] << 16;
	case 2:
		h ^= data[1] << 8;
	case 1:
		h ^= data[0] << 1;
		h *= m;
	};

	// Do a few final mixes of the hash to ensure the last few
	// bytes are well-incorporated.

	h ^= h >> 13;
	h *= m;
	h ^= h >> 15;

	return h;
}

unsigned int murmur_backup2(const void *key, int len, unsigned int seed)
{
	// 'm' and 'r' are mixing constants generated offline.
	// They're not really 'magic', they just happen to work well.

	const unsigned int m = 0x5bd1e995;
	const int r = 25;

	// Initialize the hash to a 'random' value

	unsigned int h = seed ^ len;

	// Mix 4 bytes at a time into the hash

	const unsigned char *data = (const unsigned char *)key;

	while (len >= 6)
	{
		unsigned int k = *(unsigned int *)data;

		k *= m;
		k ^= k >> r;
		k *= m;

		h *= m;
		h ^= k;

		data += 6;
		len -= 6;
	}

	// Handle the last few bytes of the input array

	switch (len)
	{
	case 3:
		h ^= data[2] << 16;
	case 2:
		h ^= data[1] << 8;
	case 1:
		h ^= data[0] << 1;
		h *= m;
	};

	// Do a few final mixes of the hash to ensure the last few
	// bytes are well-incorporated.

	h ^= h >> 13;
	h *= m;
	h ^= h >> 15;

	return h;
}
