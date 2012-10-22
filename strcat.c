#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "hello";
	char space[] = " ";
	char str1[] = "world";
	char buf[32];

	strcat(buf,str);
	strcat(buf,space);
	strcat(buf,str1);
//	printf("%s\n",buf);
        puts(buf);
	return 0;

}
