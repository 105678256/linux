#include <stdio.h>

int main()
{
        int a[10];
	int i;
	int *p;

	for (i = 0; i < 10; i++) {
		a[i] = i;
		printf("a[%d] = %d\n", i, i);
	}

	printf("p is a pointer\n");

#if 1
	p = a;
#else
	p = &a;
	printf("%p\n", p);
	p = &a[0];
	printf("%p\n", p);
#endif
	for (i = 0; i < 10; i++)
		printf("a[%d] = %d\n", i, *(p+i));

	return 0;
}


