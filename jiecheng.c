#include <stdio.h>

int fac(int n)

{if (n<0)
	return -1;
	if(n==0||n==1)
		return 1;
	return (n*fac(n - 1));
}



int main()
{
	int n = 10;
	int rat;
	rat =fac(n);
	printf("%d! = %d\n",n,rat);
	return 0;
}
