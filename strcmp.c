#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "hello";
	char str1[] = "world";
//	strcmp(str,str1);
	printf("%d\n",strcmp(str,str1));
//	printf("%d\n",strcmp(str1,str));
	return 0;
}
