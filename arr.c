#include <stdio.h>

#define N 6

int main()
{
	int i;
	int a[N];

	for(i =0;i < 6; i++)
		scanf("%d",&a[i]);
	printf("a = %p\n",a);
	for(i = 0;i<sizeof (a)/sizeof (a[0]);i++)
	//	printf("%d-->%p\n",a[i],&a[i]);
             printf("%d-->%p\n",*(a+i),(a+i));
	return 0;
}
