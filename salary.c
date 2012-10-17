#include<stdio.h>

int main (void){
	int salary=0;float rate=0.0;
	printf("please input yours salary:");
	scanf("%d",&salary);
	if (salary>50000)
		rate=.5;
	else if (salary>10000)
		rate=0.3;
	else if (salary>7000)
		rate=0.2;
	else if (salary>5000)
		rate=0.1;
	else if (salary<5000)
		rate=0;
	printf("the tax is %0.2f\n",salary*rate);
	return 0;
}
