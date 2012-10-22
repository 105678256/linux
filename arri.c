#include <stdio.h>

#define M 3
#define N 3
int main()
{
	int i, j;
	  int a[M][N] = {{65,36,78},{78,36,25},{12,25,36}};
	printf("*(a+1) = %p\n",*(a+1));
	printf("a = %p\na + 1 = %p\n",a,a + 1);
	for(i = 0;i < M; i++)
	{
		for(j = 0;j < N; j++)
			//	      printf("%4d -->%p",a[i][j],&a[i][j]);
			printf("%4d -->%p",*(*(a+1)+j),(a+1)+j);


		printf("\n");


	}
	return 0;
}
