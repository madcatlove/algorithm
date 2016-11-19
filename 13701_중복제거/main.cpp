#include <cstdio>
#define GETBIT(bit, a)  ((bit) & (1 <<(a)))
#define SETBIT(bit, a)  ((bit) | (1 <<(a)))

unsigned int d[1048589];

int main() {
	int num;
	while (scanf("%d", &num) > 0) {
		unsigned int *p = &d[num/32];
		int w = num % 32;
		if (GETBIT(*p, w)) continue;
		else {
			printf("%d ", num);
			*p = SETBIT(*p, w);
		}
	}

	return 0;
}
