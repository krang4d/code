#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>

#define COUNT 64

#define SET_BIT(BF, N) BF |= ((uint64_t)0x00000000000001 << N) 
#define CLR_BIT(BF, N) BF &= ~((uint64_t)0x00000000000001 << N)
#define IS_SET_BIT(BF, N) ((BF >> N) & 0x1)

struct counters
{
	uint8_t little:2;
	uint8_t medium:4;
	uint8_t large:6;
}__attribute__((packed));

struct counters counts;
uint64_t array_of_bits = 0;

void test_counters()
{
	counts.little = 0;
	counts.medium = 0;
	counts.large =0;

	for (int i = 0; i < COUNT; ++i)
	{
		printf("%d, %d, %d\n", counts.little++, counts.medium++, counts.large++);
	}
	printf("Sizeof counts %lu\n", sizeof(counts));
}

void test_fields()
{
	SET_BIT(array_of_bits, 1);
	SET_BIT(array_of_bits, 3);
	SET_BIT(array_of_bits, 0);
	SET_BIT(array_of_bits, 0);
	SET_BIT(array_of_bits, 7);
	SET_BIT(array_of_bits, 32);

	CLR_BIT(array_of_bits, 7);

	for (int i = 0; i < COUNT; ++i)
	{
		/* code */
		if(IS_SET_BIT(array_of_bits, i))
			printf("+");
		else printf(".");

	}
	printf("\n");
}

int main()
{
	// test_counters();
	test_fields();
}