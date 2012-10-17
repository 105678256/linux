#include <stdio.h>
int min(int a,int b,int c) 
{      int tmp;

	tmp = a < b ? a :b;
       return tmp < c ? tmp : c;

}



int max(int a, int b,int c)
	{
           int tmp;
	  tmp =  a > b ? a : b;
	return  tmp > c ? tmp :c;
	}

int cha(int a, int b,int c)
{
    return(max(a,b,c) - min(a,b,c));
} 



int main()
{ int a = 3, b = 4, c = 5;
	int sub;
	
	
sub = cha(a,b,c);

printf("sub = %d\n",sub);
	return 0;
}
