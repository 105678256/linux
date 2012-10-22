#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "hello";
	char buf[32];
	strcpy(buf,str);
	puts(buf);
	return 0;
}
