#include <stdio.h>

int main (){
	extern int date;
	printf("date=%d\n",date);
	return 0;
}
int date = 12;
