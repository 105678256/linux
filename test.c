#include<stdio.h>

int main ()
{
	int a, b, c, max;
	int tmp;

	printf("please input three numbers:a,b,c\n");

	scanf("%d,%d,%d",&a,&b,&c);
    
         tmp = a > b ? a : b;
	 max = tmp > c ? tmp : c;
	
	printf("the largest number is %d\n", max);
	return 0;


}
