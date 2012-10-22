#include <stdio.h>

#define NAME 30

	struct person{
		int id;
		char name[NAME];
		int age;
		struct birthday{
			int year;
			int month;
			int day;
		}bothday;
		
	};

int main()
{

struct person p1 = {.id=371122,.name="xiaobai",.bothday={1983,05,02}};

    printf("%d\n%s\n%d-%d-%d\n",p1.id,p1.name,p1.bothday.year,p1.bothday.month,p1.bothday.day);
    	return 0;
}
