#include<stdio.h>

 main(){
	 int key=0;

	 printf("please input a integer:");
	 scanf("%d",&key);
	 printf("key\t=%d\n",key);

	 printf("&key\t=%p\n",&key);
	 printf("*(&key)\t=%d\n",*(&key));

	 return 0;
}
