#include <stdio.h>
#include <stdlib.h>

#define MAXCACHELINES 256

// Miss penalty in cycles
#define MISSPENALTY 100

int main(int argc, char* argv[]) {
	unsigned int tags[MAXCACHELINES];
	int hit = 0, miss = 0;
	int cycles = 0;
	int linesize = 0, cachelines = 0;

	// Read args
	if (argc != 3) {
		fprintf(stderr, "usage: dmc linesize cachelines\n");
		exit(1);
	}
	linesize = atoi(argv[1]);
	cachelines = atoi(argv[2]);

	if (linesize < 4) {
		fprintf(stderr, "linesize should be >= 4\n");
		exit(1);
	}

	if (cachelines < 1) {
		fprintf(stderr, "cachelines should be >= 1\n");
		exit(1);
	}

	printf("linessize=%d cachelines=%d\n", linesize, cachelines);
	printf("\n");

	// Clear tags
	for (int i = 0; i < cachelines; i++) {
		tags[i] = 0;
	}

	// Read addresses and simulate cache
	unsigned int addr;
	while (scanf("%i", &addr) > 0) {
		unsigned int tag = addr / linesize;
		unsigned int line = tag % cachelines; 

		printf("%10u|%10u|%4u|", addr, tag, line);

		// hit
		if (tags[line] == tag) {
			hit++;
			cycles++;
			printf("H\n");
		}
		// miss
		else {
			tags[line] = tag;
			miss++;
			cycles += MISSPENALTY;
			printf("M\n");
		}
	}

	printf("\n");
	printf("hits=%d misses=%d\n", hit, miss);
	printf("hit rate=%d/(%d+%d)\n", hit, hit, miss);
	printf("cycles=%d\n", cycles);
}
